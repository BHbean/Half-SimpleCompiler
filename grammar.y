%{
#include "stdio.h"
#include <iostream>
#include "../tree/nodes.h"
#include "../symbol/symbol.h"
// #include "./tree/gtree.h"

// 为每个树节点编号
static int idx;
// 定义一颗语法树
ASTNode* root;
//定义根符号表
SymbolTable* Base;

//在lex.yy.c里定义，会被yyparse()调用。在此声明消除编译和链接错误。
extern int yylex(void); 

// 在此声明，消除yacc生成代码时的告警
extern int yyparse(void);

void yyerror(const char *s) 
{ 
    printf("[error] %s\n", s); 
}

%}

%token <str> IDENTIFIER
%token <iValue> CONSTANT
%token IF ELSE WHILE FOR RETURN
%token LE_OP GE_OP EQ_OP NE_OP LT_OP GT_OP
%token AND_OP OR_OP NOT_OP
%token <str> INT VOID
%token MAIN PRINTF SCANF

%union
{ 
    int iValue; /* integer value */ 
    //  char sIndex; /* symbol table index */ 
    char* str;
    ASTNode *ast; /* node pointer */ 
};

%left <ast> AND_OP OR_OP
%nonassoc <ast> EQ_OP NE_OP
%nonassoc <ast> LE_OP GE_OP LT_OP GT_OP
%left <ast> '+' '-'
%left <ast> '*' '/' '%'
%right <ast> '^'
%nonassoc <ast> UMINUS NOT_OP
%nonassoc IFX 
%nonassoc ELSE

%type <ast> pointer
%type <ast> var_declaration
%type <ast> init_declaration_list init_declarator declarator initializer direct_declarator
%type <ast> function_definition main_declaration
%type <ast> type_specifier
%type <ast> primary_expr
%type <ast> postfix_expr
%type <ast> unary_operator
%type <ast> assign_op
%type <ast> unary_expr
%type <ast> pow_expr
%type <ast> multiplicative_expr
%type <ast> additive_expr
%type <ast> relational_expr
%type <ast> equality_expr
%type <ast> logical_and_expr
%type <ast> logical_or_expr constant_expr
%type <ast> assign_expr
%type <ast> expression
%type <ast> comma_expr
%type <ast> for_head while_head
%type <ast> while_statement for_statement
%type <ast> read_k write_k
%type <ast> repeat_k condition_statement return_stmt statement comma_termination
%type <ast> sentence sentences semicolon_sentence
%type <ast> compound_k
%type <ast> element

%%

program:
    element{
        std::cout << "program : element" << std::endl;
        root = new ASTNode(ASTNodeType::program, idx);
        
        root->addChildNode($1);
        // std::cout << root->getChildNum() << std::endl;
        idx++;
    }
    ;

element: 
    function_definition{
        std::cout << "element : function_definition" << std::endl;
        $$ = $1;
    }
    | function_definition element{
        std::cout << "element : function_definition element" << std::endl;
        $1->setRightSibling($2);
        $$ = $1;
    }
    ;

assign_op: 
    '='{
        std::cout << "assign_op : '='" << std::endl;
        $$ = new OperatorNode(idx, "=");
        idx++;
    }
    ;

/* 把 "(expr)" 看作原初表达式是 amazing idea！ */
primary_expr:
    IDENTIFIER{
        std::cout << "primary_expr : IDENTIFIER" << std::endl;
        std::string identifier = $1;
        $$ = new IdDeclarationNode(idx, identifier);
        idx++;
    }
	| CONSTANT{
        std::cout << "primary_expr : CONSTANT" << std::endl;
        $$ = new ConstNode(idx, $1);
        idx++;
    }
	| '(' expression ')'{
        std::cout << "primary_expr : '(' expression ')'" << std::endl;
        $$ = $2;
    }
	;

postfix_expr:
    primary_expr{
        std::cout << "postfix_expr : primary_expr" << std::endl;
        $$ = $1;
    }
    | primary_expr '[' expression ']'{
        // 一维数组产生式
        std::cout << "postfix_expr : primary_expr '[' expression ']'" << std::endl;
        $$ = new OperatorNode(idx, "[]");
        idx++;
        $1->getRightestPeer()->setRightSibling($3);
        $$->addChildNode($1);
    }
    ;

unary_expr:
    postfix_expr{
        std::cout << "unary_expr : postfix_expr" << std::endl;
        $$ = $1;
    }
	| unary_operator unary_expr{
        std::cout << "unary_expr : unary_operator unary_expr" << std::endl;
        if($2->getNodeType() == ASTNodeType::constDcl){
            ((OperatorNode*)$1)->setFlag(true);
        }
        else if($2->getNodeType() == ASTNodeType::op){
            if(((OperatorNode*)$2)->getFlag()){
                ((OperatorNode*)$1)->setFlag(true);
            }
        }
        $1->addChildNode($2);
        $$ = $1;
    }
	;

/* 优先级高的单目运算符 */
unary_operator:
	'+' %prec UMINUS{
        std::cout << "unary_operator : '+'" << std::endl;
        $$ = new OperatorNode(idx, "+");
        idx++;
    }
	| '-' %prec UMINUS{
        std::cout << "unary_operator : '-'" << std::endl;
        $$ = new OperatorNode(idx, "-");
        idx++;
    }
    | NOT_OP{
        std::cout << "unary_operator : NOT_OP" << std::endl;
        $$ = new OperatorNode(idx, "!");
        idx++;
    }
    | '&'{
        // 取地址运算符
        std::cout << "unary_operator : '&'" << std::endl;
        $$ = new OperatorNode(idx, "&");
        idx++;
    }
    | '*'{
        // 取值运算符
        std::cout << "unary_operator : '*'" << std::endl;
        $$ = new OperatorNode(idx, "*");
        idx++;
    }
	;

pow_expr:
    unary_expr{
        std::cout << "pow_expr : unary_expr" << std::endl;
        $$ = $1;
    }
    | pow_expr '^' unary_expr{
        std::cout << "pow_expr : pow_expr '^' unary_expr" << std::endl;
        $$ = new OperatorNode(idx, "^");
        idx++;
        if($1->getNodeType() == ASTNodeType::constDcl){
            if($3->getNodeType() == ASTNodeType::constDcl){
                ((OperatorNode*)$$)->setFlag(true);
            }
            else if($3->getNodeType() == ASTNodeType::op){
                if(((OperatorNode*)$3)->getFlag()){
                    ((OperatorNode*)$$)->setFlag(true);
                }
            }
            ((OperatorNode*)$$)->setFlag(true);
        }
        else if($1->getNodeType() == ASTNodeType::op && ((OperatorNode*)$1)->getFlag()){
            if($3->getNodeType() == ASTNodeType::constDcl){
                ((OperatorNode*)$$)->setFlag(true);
            }
            else if($3->getNodeType() == ASTNodeType::op){
                if(((OperatorNode*)$3)->getFlag()){
                    ((OperatorNode*)$$)->setFlag(true);
                }
            }
        }
        $1->setRightSibling($3);
        $$->addChildNode($1);
    }
    ;

multiplicative_expr: 
    pow_expr{
        std::cout << "multiplicative_expr : pow_expr" << std::endl;
        $$ = $1;
    }
	| multiplicative_expr '*' pow_expr{
        std::cout << "multiplicative_expr : multiplicative_expr '*' pow_expr" << std::endl;
        $$ = new OperatorNode(idx, "*");
        idx++;
        if($1->getNodeType() == ASTNodeType::constDcl){
            if($3->getNodeType() == ASTNodeType::constDcl){
                ((OperatorNode*)$$)->setFlag(true);
            }
            else if($3->getNodeType() == ASTNodeType::op){
                if(((OperatorNode*)$3)->getFlag()){
                    ((OperatorNode*)$$)->setFlag(true);
                }
            }
            ((OperatorNode*)$$)->setFlag(true);
        }
        else if($1->getNodeType() == ASTNodeType::op  && ((OperatorNode*)$1)->getFlag()){
            if($3->getNodeType() == ASTNodeType::constDcl){
                ((OperatorNode*)$$)->setFlag(true);
            }
            else if($3->getNodeType() == ASTNodeType::op){
                if(((OperatorNode*)$3)->getFlag()){
                    ((OperatorNode*)$$)->setFlag(true);
                }
            }
        }
        $1->setRightSibling($3);
        $$->addChildNode($1);
    }
	| multiplicative_expr '/' pow_expr{
        std::cout << "multiplicative_expr : multiplicative_expr '/' pow_expr" << std::endl;
        $$ = new OperatorNode(idx, "/");
        idx++;
        if($1->getNodeType() == ASTNodeType::constDcl){
            if($3->getNodeType() == ASTNodeType::constDcl){
                ((OperatorNode*)$$)->setFlag(true);
            }
            else if($3->getNodeType() == ASTNodeType::op){
                if(((OperatorNode*)$3)->getFlag()){
                    ((OperatorNode*)$$)->setFlag(true);
                }
            }
            ((OperatorNode*)$$)->setFlag(true);
        }
        else if($1->getNodeType() == ASTNodeType::op && ((OperatorNode*)$1)->getFlag()){
            if($3->getNodeType() == ASTNodeType::constDcl){
                ((OperatorNode*)$$)->setFlag(true);
            }
            else if($3->getNodeType() == ASTNodeType::op){
                if(((OperatorNode*)$3)->getFlag()){
                    ((OperatorNode*)$$)->setFlag(true);
                }
            }
        }
        $1->setRightSibling($3);
        $$->addChildNode($1);
    }
	| multiplicative_expr '%' pow_expr{
        std::cout << "multiplicative_expr : multiplicative_expr '%' pow_expr" << std::endl;
        $$ = new OperatorNode(idx, "%");
        idx++;
        if($1->getNodeType() == ASTNodeType::constDcl){
            if($3->getNodeType() == ASTNodeType::constDcl){
                ((OperatorNode*)$$)->setFlag(true);
            }
            else if($3->getNodeType() == ASTNodeType::op){
                if(((OperatorNode*)$3)->getFlag()){
                    ((OperatorNode*)$$)->setFlag(true);
                }
            }
            ((OperatorNode*)$$)->setFlag(true);
        }
        else if($1->getNodeType() == ASTNodeType::op && ((OperatorNode*)$1)->getFlag()){
            if($3->getNodeType() == ASTNodeType::constDcl){
                ((OperatorNode*)$$)->setFlag(true);
            }
            else if($3->getNodeType() == ASTNodeType::op){
                if(((OperatorNode*)$3)->getFlag()){
                    ((OperatorNode*)$$)->setFlag(true);
                }
            }
        }
        $1->setRightSibling($3);
        $$->addChildNode($1);
    }
	;

additive_expr:
    multiplicative_expr{
        std::cout << "additive_expr : multiplicative_expr" << std::endl;
        $$ = $1;
    }
	| additive_expr '+' multiplicative_expr{
        std::cout << "additive_expr : additive_expr '+' multiplicative_expr" << std::endl;
        $$ = new OperatorNode(idx, "+");
        idx++;
        if($1->getNodeType() == ASTNodeType::constDcl){
            if($3->getNodeType() == ASTNodeType::constDcl){
                ((OperatorNode*)$$)->setFlag(true);
            }
            else if($3->getNodeType() == ASTNodeType::op){
                if(((OperatorNode*)$3)->getFlag()){
                    ((OperatorNode*)$$)->setFlag(true);
                }
            }
            ((OperatorNode*)$$)->setFlag(true);
        }
        else if($1->getNodeType() == ASTNodeType::op && ((OperatorNode*)$1)->getFlag()){
            if($3->getNodeType() == ASTNodeType::constDcl){
                ((OperatorNode*)$$)->setFlag(true);
            }
            else if($3->getNodeType() == ASTNodeType::op){
                if(((OperatorNode*)$3)->getFlag()){
                    ((OperatorNode*)$$)->setFlag(true);
                }
            }
        }
        $1->setRightSibling($3);
        $$->addChildNode($1);
    }
	| additive_expr '-' multiplicative_expr{
        std::cout << "multiplicative_expr : additive_expr '-' multiplicative_expr" << std::endl;
        $$ = new OperatorNode(idx, "-");
        idx++;
        if($1->getNodeType() == ASTNodeType::constDcl){
            if($3->getNodeType() == ASTNodeType::constDcl){
                ((OperatorNode*)$$)->setFlag(true);
            }
            else if($3->getNodeType() == ASTNodeType::op){
                if(((OperatorNode*)$3)->getFlag()){
                    ((OperatorNode*)$$)->setFlag(true);
                }
            }
            ((OperatorNode*)$$)->setFlag(true);
        }
        else if($1->getNodeType() == ASTNodeType::op && ((OperatorNode*)$1)->getFlag()){
            if($3->getNodeType() == ASTNodeType::constDcl){
                ((OperatorNode*)$$)->setFlag(true);
            }
            else if($3->getNodeType() == ASTNodeType::op){
                if(((OperatorNode*)$3)->getFlag()){
                    ((OperatorNode*)$$)->setFlag(true);
                }
            }
        }
        $1->setRightSibling($3);
        $$->addChildNode($1);
    }
	;

relational_expr:
    additive_expr{
        std::cout << "relational_expr : additive_expr" << std::endl;
        $$ = $1;
    }
	| relational_expr LT_OP additive_expr{
        std::cout << "relational_expr : relational_expr LT_OP additive_expr" << std::endl;
        $$ = new OperatorNode(idx, "<");
        idx++;
        if($1->getNodeType() == ASTNodeType::constDcl){
            if($3->getNodeType() == ASTNodeType::constDcl){
                ((OperatorNode*)$$)->setFlag(true);
            }
            else if($3->getNodeType() == ASTNodeType::op){
                if(((OperatorNode*)$3)->getFlag()){
                    ((OperatorNode*)$$)->setFlag(true);
                }
            }
            ((OperatorNode*)$$)->setFlag(true);
        }
        else if($1->getNodeType() == ASTNodeType::op && ((OperatorNode*)$1)->getFlag()){
            if($3->getNodeType() == ASTNodeType::constDcl){
                ((OperatorNode*)$$)->setFlag(true);
            }
            else if($3->getNodeType() == ASTNodeType::op){
                if(((OperatorNode*)$3)->getFlag()){
                    ((OperatorNode*)$$)->setFlag(true);
                }
            }
        }
        $1->setRightSibling($3);
        $$->addChildNode($1);
    }
	| relational_expr GT_OP additive_expr{
        std::cout << "relational_expr : relational_expr GT_OP additive_expr" << std::endl;
        $$ = new OperatorNode(idx, ">");
        idx++;
        if($1->getNodeType() == ASTNodeType::constDcl){
            if($3->getNodeType() == ASTNodeType::constDcl){
                ((OperatorNode*)$$)->setFlag(true);
            }
            else if($3->getNodeType() == ASTNodeType::op){
                if(((OperatorNode*)$3)->getFlag()){
                    ((OperatorNode*)$$)->setFlag(true);
                }
            }
            ((OperatorNode*)$$)->setFlag(true);
        }
        else if($1->getNodeType() == ASTNodeType::op && ((OperatorNode*)$1)->getFlag()){
            if($3->getNodeType() == ASTNodeType::constDcl){
                ((OperatorNode*)$$)->setFlag(true);
            }
            else if($3->getNodeType() == ASTNodeType::op){
                if(((OperatorNode*)$3)->getFlag()){
                    ((OperatorNode*)$$)->setFlag(true);
                }
            }
        }
        $1->setRightSibling($3);
        $$->addChildNode($1);
    }
	| relational_expr LE_OP additive_expr{
        std::cout << "relational_expr : relational_expr LE_OP additive_expr" << std::endl;
        $$ = new OperatorNode(idx, "<=");
        idx++;
        if($1->getNodeType() == ASTNodeType::constDcl){
            if($3->getNodeType() == ASTNodeType::constDcl){
                ((OperatorNode*)$$)->setFlag(true);
            }
            else if($3->getNodeType() == ASTNodeType::op){
                if(((OperatorNode*)$3)->getFlag()){
                    ((OperatorNode*)$$)->setFlag(true);
                }
            }
            ((OperatorNode*)$$)->setFlag(true);
        }
        else if($1->getNodeType() == ASTNodeType::op && ((OperatorNode*)$1)->getFlag()){
            if($3->getNodeType() == ASTNodeType::constDcl){
                ((OperatorNode*)$$)->setFlag(true);
            }
            else if($3->getNodeType() == ASTNodeType::op){
                if(((OperatorNode*)$3)->getFlag()){
                    ((OperatorNode*)$$)->setFlag(true);
                }
            }
        }
        $1->setRightSibling($3);
        $$->addChildNode($1);
    }
	| relational_expr GE_OP additive_expr{
        std::cout << "relational_expr : relational_expr GE_OP additive_expr" << std::endl;
        $$ = new OperatorNode(idx, ">=");
        idx++;
        if($1->getNodeType() == ASTNodeType::constDcl){
            if($3->getNodeType() == ASTNodeType::constDcl){
                ((OperatorNode*)$$)->setFlag(true);
            }
            else if($3->getNodeType() == ASTNodeType::op){
                if(((OperatorNode*)$3)->getFlag()){
                    ((OperatorNode*)$$)->setFlag(true);
                }
            }
            ((OperatorNode*)$$)->setFlag(true);
        }
        else if($1->getNodeType() == ASTNodeType::op && ((OperatorNode*)$1)->getFlag()){
            if($3->getNodeType() == ASTNodeType::constDcl){
                ((OperatorNode*)$$)->setFlag(true);
            }
            else if($3->getNodeType() == ASTNodeType::op){
                if(((OperatorNode*)$3)->getFlag()){
                    ((OperatorNode*)$$)->setFlag(true);
                }
            }
        }
        $1->setRightSibling($3);
        $$->addChildNode($1);
    }
	;

equality_expr:
    relational_expr{
        std::cout << "equality_expr : relational_expr" << std::endl;
        $$ = $1;
    }
	| equality_expr EQ_OP relational_expr{
        std::cout << "equality_expr : equality_expr EQ_OP relational_expr" << std::endl;
        $$ = new OperatorNode(idx, "==");
        idx++;
        if($1->getNodeType() == ASTNodeType::constDcl){
            if($3->getNodeType() == ASTNodeType::constDcl){
                ((OperatorNode*)$$)->setFlag(true);
            }
            else if($3->getNodeType() == ASTNodeType::op){
                if(((OperatorNode*)$3)->getFlag()){
                    ((OperatorNode*)$$)->setFlag(true);
                }
            }
            ((OperatorNode*)$$)->setFlag(true);
        }
        else if($1->getNodeType() == ASTNodeType::op && ((OperatorNode*)$1)->getFlag()){
            if($3->getNodeType() == ASTNodeType::constDcl){
                ((OperatorNode*)$$)->setFlag(true);
            }
            else if($3->getNodeType() == ASTNodeType::op){
                if(((OperatorNode*)$3)->getFlag()){
                    ((OperatorNode*)$$)->setFlag(true);
                }
            }
        }
        $1->setRightSibling($3);
        $$->addChildNode($1);
    }
	| equality_expr NE_OP relational_expr{
        std::cout << "equality_expr : equality_expr NE_OP relational_expr" << std::endl;
        $$ = new OperatorNode(idx, "!=");
        idx++;
        if($1->getNodeType() == ASTNodeType::constDcl){
            if($3->getNodeType() == ASTNodeType::constDcl){
                ((OperatorNode*)$$)->setFlag(true);
            }
            else if($3->getNodeType() == ASTNodeType::op){
                if(((OperatorNode*)$3)->getFlag()){
                    ((OperatorNode*)$$)->setFlag(true);
                }
            }
            ((OperatorNode*)$$)->setFlag(true);
        }
        else if($1->getNodeType() == ASTNodeType::op && ((OperatorNode*)$1)->getFlag()){
            if($3->getNodeType() == ASTNodeType::constDcl){
                ((OperatorNode*)$$)->setFlag(true);
            }
            else if($3->getNodeType() == ASTNodeType::op){
                if(((OperatorNode*)$3)->getFlag()){
                    ((OperatorNode*)$$)->setFlag(true);
                }
            }
        }
        $1->setRightSibling($3);
        $$->addChildNode($1);
    }
	;

logical_and_expr:
    equality_expr{
        std::cout << "logical_and_expr : equality_expr" << std::endl;
        $$ = $1;
    }
	| logical_and_expr AND_OP equality_expr{
        std::cout << "logical_and_expr : logical_and_expr AND_OP equality_expr" << std::endl;
        $$ = new OperatorNode(idx, "&&");
        idx++;
        if($1->getNodeType() == ASTNodeType::constDcl){
            if($3->getNodeType() == ASTNodeType::constDcl){
                ((OperatorNode*)$$)->setFlag(true);
            }
            else if($3->getNodeType() == ASTNodeType::op){
                if(((OperatorNode*)$3)->getFlag()){
                    ((OperatorNode*)$$)->setFlag(true);
                }
            }
            ((OperatorNode*)$$)->setFlag(true);
        }
        else if($1->getNodeType() == ASTNodeType::op && ((OperatorNode*)$1)->getFlag()){
            if($3->getNodeType() == ASTNodeType::constDcl){
                ((OperatorNode*)$$)->setFlag(true);
            }
            else if($3->getNodeType() == ASTNodeType::op){
                if(((OperatorNode*)$3)->getFlag()){
                    ((OperatorNode*)$$)->setFlag(true);
                }
            }
        }
        $1->setRightSibling($3);
        $$->addChildNode($1);
    }
	;

logical_or_expr:
    logical_and_expr{
        std::cout << "logical_or_expr : logical_and_expr" << std::endl;
        $$ = $1;
    }
	| logical_or_expr OR_OP logical_and_expr{
        std::cout << "logical_or_expr : logical_or_expr OR_OP logical_and_expr" << std::endl;
        $$ = new OperatorNode(idx, "||");
        idx++;
        if($1->getNodeType() == ASTNodeType::constDcl){
            if($3->getNodeType() == ASTNodeType::constDcl){
                ((OperatorNode*)$$)->setFlag(true);
            }
            else if($3->getNodeType() == ASTNodeType::op){
                if(((OperatorNode*)$3)->getFlag()){
                    ((OperatorNode*)$$)->setFlag(true);
                }
            }
            ((OperatorNode*)$$)->setFlag(true);
        }
        else if($1->getNodeType() == ASTNodeType::op && ((OperatorNode*)$1)->getFlag()){
            if($3->getNodeType() == ASTNodeType::constDcl){
                ((OperatorNode*)$$)->setFlag(true);
            }
            else if($3->getNodeType() == ASTNodeType::op){
                if(((OperatorNode*)$3)->getFlag()){
                    ((OperatorNode*)$$)->setFlag(true);
                }
            }
        }
        $1->setRightSibling($3);
        $$->addChildNode($1);
    }
	;

assign_expr:
    logical_or_expr{
        std::cout << "assign_expr : logical_or_expr" << std::endl;
        $$ = $1;
    }
	| unary_expr assign_op assign_expr{
        std::cout << "logical_or_expr : logical_or_expr OR_OP logical_and_expr" << std::endl;
        $1->setRightSibling($3);
        $2->addChildNode($1);
        $$ = $2;
    }
	;

expression:
    assign_expr{
        std::cout << "expression : assign_expr" << std::endl;
        $$ = $1;
    }
	| expression ',' assign_expr{
        std::cout << "expression : expression ',' assign_expr" << std::endl;
        $1->getRightestPeer()->setRightSibling($3);
        $$ = $1;
    }
    ;

constant_expr:
    logical_or_expr{
        std::cout << "constant_expr : logical_or_expr" << std::endl;
        $$ = $1;
    }
    ;

type_specifier: 
    INT{
        std::cout << "type_specifier: INT" << std::endl;
        $$ = new TypeSpcfNode(idx, "int");
        idx++;
    }
    | VOID{
        std::cout << "type_specifier: VOID" << std::endl;
        $$ = new TypeSpcfNode(idx, "void");
        idx++;
    }
    ;

/*
暂不考虑其他函数的定义
function_definition: 
    type_specifier IDENTIFIER '(' ')' compound_k{
        $$ = new ASTNode(ASTNodeType::defFunc, idx);

    }
    | main_function
    ;
*/

function_definition: 
    main_declaration compound_k{
        std::cout << "function_definition: main_declaration compound_k" << std::endl;
        // if(NULL != $1){
        //     std::cout << "main_declaration construction successed!" << std::endl;
        // }
        $1->setRightSibling($2);
        $$ = new ASTNode(ASTNodeType::defFunc, idx);
        idx++;
        $$->addChildNode($1);
        CompoundNode* current_node = dynamic_cast<CompoundNode*>($2);
        current_node->getTable()->setBase(Base);
        Base->addChild(current_node->getTable());
        std::vector<SymbolTable*>* test_vec = Base->getChild();
        for(auto test_iter = (*test_vec).begin();test_iter != (*test_vec).end();test_iter++){
            std::cout<<"                                                 child "<<std::endl;
        }
        //std::cout<<"                                                              ha"<<std::endl;
        // CompoundNode* current_node = dynamic_cast<CompoundNode*>($2);
        // Base = current_node->getTable();
        // if(!Base->getChild()->empty()){
        //     std::vector<SymbolTable*>* test_vec = Base->getChild();
        //     for(auto test_iter = (*test_vec).begin();test_iter != (*test_vec).end();test_iter++){
        //         /*设置根符号表*/
        //         (*test_iter)->setBase(Base);
        //     }
            
        // }


        // if(NULL != $$){
        //     std::cout << "function_definition construction successed!" << std::endl;
        // }
    }
    ;

main_declaration: 
    type_specifier MAIN '(' ')'{
        std::cout << "main_declaration: type_specifier MAIN '(' ')'" << std::endl;
        $$ = new ASTNode(ASTNodeType::mainFunc, idx);
        idx++;
        $$->addChildNode($1);
    }
    ;

compound_k:
    '{' statement '}'{ //如何找到作用域的子作用域，然后通过父子结点连接起来   每当遇到{}便会遍历该节点向下的id然后插入符号表，如何遍历
        std::cout << "compound_k : '{' statement '}'" << std::endl;
        $$ = new CompoundNode(idx);
        idx++;
        $$->addChildNode($2);
        CompoundNode* current_node = dynamic_cast<CompoundNode*>($$);
        if($$->getChild()->empty()){
            //current_node->getTable()->setBase(Base);
            //std::cout<<"                                                              ha"<<std::endl;
        } //如果没有子结点
        else{ //如果存在子结点           
	        std::vector<ASTNode*>* tmp = $$->getChild();
            for(auto it = (*tmp).begin();it != (*tmp).end();it++){ //遍历子结点
                if((*it)->getNodeType()==ASTNodeType::compoudStmt){ //enum中定义的compoudStmt而不是compoundStmt
                //Derived *pD = dynamic_cast<Derived*>(pB);
                    CompoundNode * compound_it = dynamic_cast<CompoundNode*>(*it);
                    
                    //*it = CompoundNode* (*it);                  
                    compound_it->getTable()->setParent(current_node->getTable());
                    compound_it->getTable()->setBase(Base);
                    Base->addChild(compound_it->getTable());
                    
                    // std::vector<SymbolTable*>* test_vec = Base->getChild();
                    // for(auto test_iter = (*test_vec).begin();test_iter != (*test_vec).end();test_iter++){
                    //     std::cout<<"                                                 child "<<std::endl;
                    // }
                    current_node->getTable()->addChild(compound_it->getTable());
                    //std::cout<<"YesYYYYYYYY"<<std::endl;
                    //std::cout<<"AAAAAAAAAAAA"<<std::endl; 
                }else if((*it)->getNodeType()==ASTNodeType::reapeatStmt){ 
                    /*循环语句需寻找子结点的compoundStmt
                     -- 循环语句的()和{}都是子作用域，需要进行进一步判断
                     -- 根据当前产生式不需要考虑这一点*/
                    if((*it)->getChild()->empty()){}
                    else{

                        std::vector<ASTNode*>* child_tmp = (*it)->getChild();
                        for(auto iter =(*child_tmp).begin();iter != (*child_tmp).end();iter++){
                            if((*iter)->getNodeType()==ASTNodeType::compoudStmt){ //如果是{}
                                
                                CompoundNode * compound_it_re = dynamic_cast<CompoundNode*>(*iter);
                                compound_it_re->getTable()->setParent(current_node->getTable());
                                compound_it_re->getTable()->setBase(Base);
                                Base->addChild(compound_it_re->getTable());
                                // std::vector<SymbolTable*>* test_vec = Base->getChild();
                                // for(auto test_iter = (*test_vec).begin();test_iter != (*test_vec).end();test_iter++){
                                //     std::cout<<"                                                 child "<<std::endl;
                                // }
                                current_node->getTable()->addChild(compound_it_re->getTable());
                            }//else if((*iter)->getNodeType()==ASTNodeType::compoudStmt){} //如果是()
                        }
                    }

                }else if((*it)->getNodeType()==ASTNodeType::conditionStmt){ //条件判断语句
                    if((*it)->getChild()->empty()){}
                    else{
                        std::vector<ASTNode*>* child_tmp_1 = (*it)->getChild();
                        for(auto iter_1 =(*child_tmp_1).begin();iter_1 != (*child_tmp_1).end();iter_1++){
                            if((*iter_1)->getNodeType()==ASTNodeType::compoudStmt){
                                CompoundNode * compound_it_con = dynamic_cast<CompoundNode*>(*iter_1);
                                compound_it_con->getTable()->setParent(current_node->getTable());
                                Base->addChild(compound_it_con->getTable());
                                compound_it_con->getTable()->setBase(Base);
                                // std::vector<SymbolTable*>* test_vec = Base->getChild();
                                // for(auto test_iter = (*test_vec).begin();test_iter != (*test_vec).end();test_iter++){
                                //     std::cout<<"                                                 child "<<std::endl;
                                // }
                                current_node->getTable()->addChild(compound_it_con->getTable());
                            }
                        }
                    }

                }else if((*it)->getNodeType()==ASTNodeType::varDcl){ //声明变量语句
                    if(!(*it)->getChild()->empty()){ //如果子结点不为空
                        std::vector<ASTNode*>* child_tmp_2 = (*it)->getChild();
                        // for(auto iter_2 = (*child_tmp_2).begin;iter_2 != (*child_tmp_2).end();iter_2++){
                        // }
                        ASTNode * init_del_list = (*child_tmp_2)[0]->getRightSibling();
                        
                        
                        while(init_del_list->getRightSibling() != NULL){
                            ASTNode * init_del = init_del_list;
                            if(init_del->getChild()->empty()){ //int b 的形式
                                
                                IdDeclarationNode * del_it_var = dynamic_cast<IdDeclarationNode*>(init_del);
                                if(current_node->getTable()-> IfInThisTable(del_it_var->getSymbol()->getname())==1){
                                    std::cout<<"重定义错误！"<<del_it_var->getSymbol()->getname()<<std::endl;
                                }else{
                                    current_node->getTable()->addSymbol(del_it_var->getSymbol());
                                }
                                
                        
                            }
                            else{
                                //数组
                                if(init_del->getNodeType() == ASTNodeType::arrayDcl){
                                    std::vector<ASTNode*>* child_tmp_3 = init_del->getChild();
                                    ASTNode * del_it_var_tmp = (*child_tmp_3)[0];
                                    IdDeclarationNode * del_it_var = dynamic_cast<IdDeclarationNode*>(del_it_var_tmp);
                                    OperatorNode * array_del_1 = dynamic_cast<OperatorNode*>(init_del);
                                    //bool tmpflag = array_del_1->getFlag();
                                    //if(tmpflag==true){}
                                    //else{}
                                    if(current_node->getTable()-> IfInThisTable(del_it_var->getSymbol()->getname())==1){
                                        std::cout<<"重定义错误！"<<del_it_var->getSymbol()->getname()<<std::endl;
                                    }else{
                                        //向符号表中插入标识符
                                        //current_node->getTable()->addSymbol(del_it_var->getSymbol());
                                    
                                    }
                                }
                                else{ //id或指针
                                std::vector<ASTNode*>* child_tmp_3 = init_del->getChild();
                                ASTNode * del_it_var_tmp = (*child_tmp_3)[0];
                                if (del_it_var_tmp->getChild()->empty()){ //子结点为空，是一个iddecl
                                IdDeclarationNode * del_it_var = dynamic_cast<IdDeclarationNode*>(del_it_var_tmp);
                                if(current_node->getTable()-> IfInThisTable(del_it_var->getSymbol()->getname())==1){
                                    std::cout<<"重定义错误！"<<del_it_var->getSymbol()->getname()<<std::endl;
                                }else{
                                    //向符号表中插入标识符
                                    current_node->getTable()->addSymbol(del_it_var->getSymbol());
                                    
                                }
                                }
                                else{
                                    //是一个指针
                                    std::vector<ASTNode*>* child_tmp_4 = del_it_var_tmp->getChild();
                                    ASTNode * pointer_del_1 = (*child_tmp_4)[0];
                                    IdDeclarationNode * del_it_pointer = dynamic_cast<IdDeclarationNode*>(pointer_del_1);
                                    if(current_node->getTable()-> IfInThisTable(del_it_pointer->getSymbol()->getname())==1){
                                        std::cout<<"重定义错误！"<<del_it_pointer->getSymbol()->getname()<<std::endl;
                                    }else{
                                    //向符号表中插入标识符
                                    current_node->getTable()->addSymbol(del_it_pointer->getSymbol());
                                    }
                                }
                                }
                                
                            }
                            init_del_list = init_del_list->getRightSibling();
                        }
                        if(init_del_list->getRightSibling()==NULL){ //右结点为空，两种情况，即原本就没有右结点或遍历到最后一个结点
                            ASTNode * init_del = init_del_list;
                            
                            if(init_del->getChild()->empty()){
                                IdDeclarationNode * del_it_var = dynamic_cast<IdDeclarationNode*>(init_del);
                                if(current_node->getTable()-> IfInThisTable(del_it_var->getSymbol()->getname())==1){
                                    std::cout<<"重定义错误！"<<del_it_var->getSymbol()->getname()<<std::endl;
                                }else{

                                    current_node->getTable()->addSymbol(del_it_var->getSymbol());

                                }
                                //std::cout<<"                                                       this is decloator1"<<del_it_var->getSymbol()->getname()<<std::endl;
                            }
                            // else{
                            //     std::vector<ASTNode*>* child_tmp_3 = init_del->getChild();
                            //     ASTNode * del_it_var_tmp = (*child_tmp_3)[0];
                            //     IdDeclarationNode * del_it_var = dynamic_cast<IdDeclarationNode*>(del_it_var_tmp);
                            //     if(current_node->getTable()-> IfInThisTable(del_it_var->getSymbol()->getname())==1){
                            //         std::cout<<"重定义错误！"<<del_it_var->getSymbol()->getname()<<std::endl;
                            //     }
                            else{
                                //数组
                                if(init_del->getNodeType() == ASTNodeType::arrayDcl){
                                    std::vector<ASTNode*>* child_tmp_3 = init_del->getChild();
                                    ASTNode * del_it_var_tmp = (*child_tmp_3)[0];
                                    IdDeclarationNode * del_it_var = dynamic_cast<IdDeclarationNode*>(del_it_var_tmp);
                                    OperatorNode * array_del_1 = dynamic_cast<OperatorNode*>(init_del);
                                    //bool tmpflag = array_del_1->getFlag();
                                    //if(tmpflag==true){}
                                    //else{}
                                    if(current_node->getTable()-> IfInThisTable(del_it_var->getSymbol()->getname())==1){
                                        std::cout<<"重定义错误！"<<del_it_var->getSymbol()->getname()<<std::endl;
                                    }else{
                                        //向符号表中插入标识符
                                        //current_node->getTable()->addSymbol(del_it_var->getSymbol());
                                    
                                    }
                                }
                                else{ //id或指针
                                std::vector<ASTNode*>* child_tmp_3 = init_del->getChild();
                                ASTNode * del_it_var_tmp = (*child_tmp_3)[0];
                                if (del_it_var_tmp->getChild()->empty()){ //子结点为空，是一个iddecl
                                IdDeclarationNode * del_it_var = dynamic_cast<IdDeclarationNode*>(del_it_var_tmp);
                                if(current_node->getTable()-> IfInThisTable(del_it_var->getSymbol()->getname())==1){
                                    std::cout<<"重定义错误！"<<del_it_var->getSymbol()->getname()<<std::endl;
                                }else{
                                    //向符号表中插入标识符
                                    current_node->getTable()->addSymbol(del_it_var->getSymbol());
                                    
                                }
                                }
                                else{
                                    //是一个指针
                                    std::vector<ASTNode*>* child_tmp_4 = del_it_var_tmp->getChild();
                                    ASTNode * pointer_del_1 = (*child_tmp_4)[0];
                                    IdDeclarationNode * del_it_pointer = dynamic_cast<IdDeclarationNode*>(pointer_del_1);
                                    if(current_node->getTable()-> IfInThisTable(del_it_pointer->getSymbol()->getname())==1){
                                        std::cout<<"重定义错误！"<<del_it_pointer->getSymbol()->getname()<<std::endl;
                                    }else{
                                    //向符号表中插入标识符
                                    current_node->getTable()->addSymbol(del_it_pointer->getSymbol());
                                    }
                                }
                                }
                                
                            
                            
                            }
                        }
                        

                    }

                }
            }
        }
        /*测试符号表是否连接
        int test = 1;
        SymbolTable *test_table = new SymbolTable(); 
        test_table = current_node->getTable();
        
        if(!test_table->getChild()->empty()){
            std::vector<SymbolTable*>* test_vec = test_table->getChild();
            for(auto test_iter = (*test_vec).begin();test_iter != (*test_vec).end();test_iter++){
                std::cout<<test<<"                                                    jjjjjjjjjjjjjjjjjjj"<<std::endl;
                test++;
                //test_table = test_table->getChild(); 
            }
            
        }*/
    }
    | '{' '}'{
        std::cout << "compound_k : '{' '}'" << std::endl;
        $$ = new CompoundNode(idx);
        idx++;
    }
    ;

sentences:
    sentence{
        std::cout << "sentences : sentence" << std::endl;
        $$ = $1;
    }
    | compound_k{
        std::cout << "sentences : compound_k" << std::endl;
        $$ = $1;
    }
    ;

statement:
    sentences{
        std::cout << "statement : sentences" << std::endl;
        $$ = $1;
    }
    | statement sentences{
        std::cout << "statement : statement sentences" << std::endl;
        $1->getRightestPeer()->setRightSibling($2);
        $$ = $1;
    }
    ;

// 指针符号 * 
pointer:
    '*'{
        std::cout << "pointer : '*'" << std::endl;
        $$ = new ASTNode(ASTNodeType::ptrDcl, idx);
        idx++;
    }
    ;

var_declaration:
    type_specifier init_declaration_list{
        std::cout << "var_declaration: type_specifier init_declaration_list" << std::endl;
        $$ = new ASTNode(ASTNodeType::varDcl, idx);
        idx++;
        $1->setRightSibling($2);
        $$->addChildNode($1);
    }
    ;

init_declaration_list:
    init_declarator{
        std::cout << "init_declaration_list: init_declarator" << std::endl;
        $$ = $1;
    }
    | init_declaration_list ',' init_declarator{
        std::cout << "init_declaration_list: init_declarator_list ',' init_declarator" << std::endl;
        $1->getRightestPeer()->setRightSibling($3);
        $$ = $1;
    }
    ;

init_declarator:
    declarator{
        std::cout << "init_declarator: declarator" << std::endl;
        $$ = $1;
    }
    | declarator assign_op initializer{
        std::cout << "init_declarator: declarator assign_op initializer" << std::endl;
        $1->setRightSibling($3);
        $2->addChildNode($1);
        $$ = $2;
    }
    ;

declarator:
    pointer direct_declarator{
        std::cout << "declarator : pointer direct_declarator" << std::endl;
        IdDeclarationNode * idNode = dynamic_cast<IdDeclarationNode*>($2);
        Symbol * tmp_symbol1 = idNode->getSymbol();
        tmp_symbol1->change(idNode->getIdentifier(),SymbolType::pointer);
        $$ = $1;
        $1->addChildNode($2);
    }
    | direct_declarator{
        std::cout << "declarator : direct_declarator" << std::endl;
        $$ = $1;
    }
    | direct_declarator '[' constant_expr ']'{
        $$ = new ASTNode(ASTNodeType::arrayDcl, idx);
        IdDeclarationNode * idNode_2 = dynamic_cast<IdDeclarationNode*>($1);
        Symbol * tmp_symbol2 = idNode_2->getSymbol();
        tmp_symbol2->change(idNode_2->getIdentifier(),SymbolType::array);
        idx ++;
        if($3->getNodeType() == ASTNodeType::op){
            // std::cout << "********************in**************************" << std::endl;
            if(((OperatorNode*)$3)->getFlag() == false){
                std::cout << "In array declaration, the expression in '['']' has to be constant expression!" << std::endl;
                exit(0);
            }
        }
        $1->setRightSibling($3);
        $$->addChildNode($1);
    }
    ;

direct_declarator:
    IDENTIFIER{
        std::cout << "direct_declarator: IDENTIFIER" << std::endl;
        std::string str = $1;
        $$ = new IdDeclarationNode(idx, str);
        idx++;
    }
    | '(' direct_declarator ')'{
        std::cout << "direct_declarator: '(' direct_declarator ')'" << std::endl;
        $$ = $2;
    }
    ;

initializer:
    assign_expr{
        std::cout << "initializer: assign_expr" << std::endl;
        $$ = $1;
    }
    ;

comma_expr:
    expression{
        std::cout << "comma_expr: expression" << std::endl;
        $$ = $1;
    }
    | comma_expr ',' comma_expr{
        std::cout << "comma_expr: comma_expr ',' comma_expr" << std::endl;
        $1->getRightestPeer()->setRightSibling($3);
        $$ = $1;
    }
    | /* empty string */{
        std::cout << "comma_expr: ε" << std::endl;
        $$ = NULL;
    }
    | write_k{
        std::cout << "comma_expr: write_k" << std::endl;
        $$ = $1;
    }
    | read_k{
        std::cout << "comma_expr: read_k" << std::endl;
        $$ = $1;
    }
    ;

comma_termination:
    comma_expr ';'{
        std::cout << "comma_termination: comma_expr ';'" << std::endl;
        $$ = $1;
    }
    ;

semicolon_sentence:
    comma_termination{
        std::cout << "semicolon_sentence: comma_termination ';'" << std::endl;
        $$ = $1;
    }
    | var_declaration ';'{
        std::cout << "semicolon_sentence: var_declaration ';'" << std::endl;
        $$ = $1;
    }
    ;

sentence:
    semicolon_sentence{
        std::cout << "sentence: semicolon_sentence" << std::endl;
        $$ = $1;
    }
    | repeat_k{
        std::cout << "sentence: repeat_k" << std::endl;
        $$ = $1;
    }
    | condition_statement{
        std::cout << "sentence: condition_statement" << std::endl;
        $$ = $1;
    }
    | return_stmt{
        std::cout << "sentence: return_stmt" << std::endl;
        $$ = $1;
    }
    ;

repeat_k:
    for_statement{
        std::cout << "repeat_k: for_statement" << std::endl;
        $$ = new RepeatNode(idx, "for");
        idx++;
        $$->addChildNode($1);
    }
    | while_statement{
        std::cout << "repeat_k: for_statement" << std::endl;
        $$ = new RepeatNode(idx, "while");
        idx++;
        $$->addChildNode($1);
    }
    ;

for_head:
    FOR '(' semicolon_sentence comma_termination comma_expr ')'{
        std::cout << "for_head: FOR '(' semicolon_sentence comma_termination comma_expr ')'" 
                  << std::endl;
        if($3 != NULL){
            $3->getRightestPeer()->setRightSibling($4);
            $$ = $3;
        }
        $4->getRightestPeer()->setRightSibling($5);
        if($3 == NULL){
            $$ = $4;
        }
    }
    ;

for_statement:
    for_head sentences{
        std::cout << "for_statement: for_head sentences" << std::endl;
        $1->getRightestPeer()->setRightSibling($2);
        $$ = $1;
    }
    ;

while_head:
    WHILE '(' comma_expr ')'{
        std::cout << "while_head: WHILE '(' comma_expr ')'" << std::endl;
        $$ = $3;
    }
    ;

while_statement:
    while_head sentences{
        std::cout << "while_statement: while_head sentences" << std::endl;
        $1->getRightestPeer()->setRightSibling($2);
        $$ = $1;
    }
    ;

write_k:
    PRINTF '(' IDENTIFIER ')'{
        std::cout << "write_k: PRINTF '(' IDENTIFIER ')'" << std::endl;
        std::string str = $3;
        ASTNode* tmp = new IdDeclarationNode(idx, str);
        idx++;
        $$ = new ASTNode(ASTNodeType::writeFunc, idx);
        idx++;
        $$->addChildNode(tmp);
    }
    | PRINTF '(' CONSTANT ')'{
        std::cout << "write_k: PRINTF '(' CONSTANT ')'" << std::endl;
        ASTNode* tmp = new ConstNode(idx, $3);
        idx++;
        $$ = new ASTNode(ASTNodeType::writeFunc, idx);
        idx++;
        $$->addChildNode(tmp);
    }
    ;

read_k:
    SCANF '(' IDENTIFIER ')'{
        std::cout << "read_k: SCANF '(' IDENTIFIER ')'" << std::endl;
        std::string str = $3;
        ASTNode* tmp = new IdDeclarationNode(idx, str);
        idx++;
        $$ = new ASTNode(ASTNodeType::readFunc, idx);
        idx++;
        $$->addChildNode(tmp);
    }
    ;

condition_statement:
    IF '(' comma_expr ')' sentences %prec IFX{
        std::cout << "condition_statement: IF '(' comma_expr ')' sentences" << std::endl;
        $$ = new ASTNode(ASTNodeType::conditionStmt, idx);
        idx++;
        $3->getRightestPeer()->setRightSibling($5);
        $$->addChildNode($3);
    }
    | IF '(' comma_expr ')' sentences ELSE sentences{
        std::cout << "condition_statement: IF '(' comma_expr ')' sentences ELSE sentences" 
                  << std::endl;
        $$ = new ASTNode(ASTNodeType::conditionStmt, idx);
        idx++;
        $3->getRightestPeer()->setRightSibling($5);
        $5->getRightestPeer()->setRightSibling($7);
        $$->addChildNode($3);
    }
    ;

return_stmt:
    RETURN ';'{
        std::cout << "return_stmt: RETURN ';'" << std::endl;
        $$ = new ASTNode(ASTNodeType::returnStmt, idx);
        idx++;
    }
    ;
%%

// #include "lex.yy.c"
int main()
{
    Base = new SymbolTable();
    Base->settotalOffset(4);
    Base->setsymbolItemCount(0);
    Base->setBase(Base);
    yyparse();
    // if(NULL != root){
    //     std::cout << "root exists!" << std::endl;
    // }

    ASTNode::printTree(root);
    return 0;
}
