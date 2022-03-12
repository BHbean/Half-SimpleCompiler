
%{
#include "stdio.h"
#include "stdlib.h"
#include "grammar.tab.h"

extern YYSTYPE yylval;
%}


int_number [1-9][0-9]*|[0]
float_number [0-9]*[.][0-9]+([eE][+-]?[0-9]*|[0])?f?
semicolon [;]
comma [,]
assignop [=]
greater [>]
less [<]
greater_or_equal [>][=]
less_or_equal [<][=]
equal [=][=]
not_equal [!][=]
get_addr [&]
plus [+]
minus [-]
multiply [*]
div [/]
remainder [%]
pow \^
and [&][&]
or [|][|]
dot [.]
not [!]
type int
lp \(
rp \)
lb \[
rb \]
lc \{
rc \}
scanf scanf
printf printf
struct struct
return return
main main
void void
if if
else else 
while while
for for
ann ([*][^/]|[^*])*
space [ \n\t]
id [a-zA-Z_][a-zA-Z_0-9]*
/*end of definition*/

%%

"//".* {}  //注释符

"/*"{ann}*"*/" {}  //注释符

{semicolon} {
    printf(";\n");
    return(';');
}

{comma} {
    printf(",\n");
    return(',');
}

{assignop} {
    printf("=\n");
    return('=');
}

{int_number} {
    printf("%s\n", yytext);
    yylval.iValue = atoi(yytext);
    return(CONSTANT);
}

{get_addr} {
    printf("&\n");
    return('&');
}

{plus} {
    printf("+\n");
    return('+');
} 
{minus} {
    printf("-\n");
    return('-');
}
{div} {
    printf("/\n");
    return('/');
}
{multiply} {
    printf("*\n");
    return('*');
}
{remainder} {
    printf("\%\n");
    return('%');
}
{pow} {
    printf("^\n");
    return('^');
}

{less} {
    printf("<\n");
    return(LT_OP);
}
{greater} {
    printf(">\n");
    return(GT_OP);
}
{less_or_equal} {
    printf("<=\n");
    return(LE_OP);
}
{greater_or_equal} {
    printf(">=\n");
    return(GE_OP);
}
{equal} {
    printf("==\n");
    return(EQ_OP);
}
{not_equal} {
    printf("!=\n");
    return(NE_OP);
}

{and} {
    printf("&&\n");
    return(AND_OP);
}
{or} {
    printf("||\n");
    return(OR_OP);
}
{not} {
    printf("!\n");
    return(NOT_OP);
}

{scanf} {
    printf("scanf\n");
    return(SCANF);
}
{printf} {
    printf("printf\n");
    return(PRINTF);
}
{return} {
    printf("return\n");
    return(RETURN);
}
{if} {
    printf("if\n");
    return(IF);
}
{else} {
    printf("else\n");
    return(ELSE);
}
{for} {
    printf("for\n");
    return(FOR);
}
{while} {
    printf("while\n");
    return(WHILE);
}
{main} {
    printf("main\n");
    return(MAIN);
}

{void} {
    printf("void\n");
    yylval.str = strdup(yytext);
    return(VOID);
}

{type} {
    printf("int\n");
    yylval.str = strdup(yytext);
    return(INT);
}

{lp} {
    printf("(\n");
    return('(');
}
{rp} {
    printf(")\n");
    return(')');
}
{lb} {
    printf("[\n");
    return('[');
}
{rb} {
    printf("]\n");
    return(']');
}
{lc} {
    printf("{\n");
    return('{');
}
{rc} {
    printf("}\n");
    return('}');
}


{id} {
    printf("%s\n", yytext);
    yylval.str = strdup(yytext);
    return(IDENTIFIER);
}
{space} |
. {
    //printf("can't recognize!\n");
    /*ABANDON THESE CHARACTORS*/
}
%%

/*
以下三条命令可展示词法分析器功能，其中input.txt为输入文件
flex scanner.l
gcc lex.yy.c -o scanner
./scanner input.txt 
*/

int yywrap() {
  return 1;
}

// int main(int argc, char** argv) {
//    if (argc > 1) {
//        if (!(yyin = fopen(argv[1], "r"))) {   
//            perror(argv[1]);
//            return 1;
//        }
//    }
//    while (yylex());
//    return 0;
// }
