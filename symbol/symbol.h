#ifndef SYMBOL_H
#define SYMBOL_H
#include<iostream>
#include<string>
#include<vector>
#include<unordered_map>
// #include "../tree/ASTNode.h"
// #include "../tree/IdDeclarationNode.h"
// #include "../tree/OperatorNode.h"

#define INT_OFFSET 4

enum class SymbolType {
	none = 0,
	integer = 1,
	pointer = 2,
	boolean = 3,
	array = 4
};


class Symbol {

protected:
	std::string name;
	SymbolType type;
	int offset;
	int index;

public:
	/*默认初始化*/
	Symbol();
	/*有参初始化*/
	Symbol(std::string name, SymbolType type);

	/*得到符号的属性*/
	std::string getname();
	SymbolType &gettype();
	SymbolType getType() { return this->type;}
	// std::string gettypeString();

	int getOffset() { return offset;}
	int getIndex() { return index;}
	void setOffset(int offset) { this->offset = offset;}
	void setIndex(int index) {this->index = index;}

	void change(std::string name, SymbolType type); //修改符号的属性——name,type
};


class SymbolTable {

private:
	std::unordered_map<std::string, Symbol *> SymbolHashtable; //哈希表存储变量，<符号名称,符号指针-包含符号的各种属性>
	
	//std::vector<Symbol *> *argArray;
	SymbolTable * baseTable; //根作用域
	SymbolTable * parentTable;
	std::vector<SymbolTable*>* childTable;
	//SymbolTable * childTable;
	
	// 符号表的唯一标识Num
	int id_num;

	std::vector<Symbol *> *symbolArray;
    // 根作用域保存该作用域下总符号数目
	int symbolItemCount;
	// 当前作用域的总偏移量
	int totalOffset;


public:
    
	SymbolTable();

	/*用于测试的符号表打印函数*/
	void printSymbol();

	/*增删改查
	参数只有单个符号的地址
	故先修改符号再将修改后的符号作为参数修改符号表*/
	int addSymbol(Symbol *symbol); //返回true即1则添加成功，返回false即0则插入失败--重定义错误
	//int addArraySymbol()
	void delSymbol(Symbol *symbol);
	int changeSymbol(Symbol *symbol); //返回true即1则修改成功，返回false即0则未造成修改
	//Symbol* searchSymbol(Symbol *symbol);
	Symbol* searchSymbol(std::string symbol_name);
	
	/*查看该符号是否在当前的作用域*/
	int IfInThisTable(std::string name);

	/*设置父子符号表；返回父子符号表指针*/
	void addChild(SymbolTable * node);
	inline void setParent(SymbolTable * ParentTable) { this->parentTable = ParentTable; }
	inline void setBase(SymbolTable * BaseTable) {this->baseTable = BaseTable; }
	inline SymbolTable * getParent() { return this->parentTable; }
	inline std::vector<SymbolTable*>* getChild() { return this->childTable; }
    inline int getsymbolItemCount() { return this->symbolItemCount;}
	inline int getTotalOffset() { return this->totalOffset;}
	void settotalOffset(int offset) { this->totalOffset = offset;}
	void setsymbolItemCount(int count) { this->symbolItemCount = count;}
	void push_array(Symbol* symbol) {this->symbolArray->push_back(symbol);}
	void test() {std::cout<<"111111111111111111111111111111111111111111111111111123"<<std::endl;}

	
	//Num_Id
	inline int getId_Num() {return this->id_num;}
	inline void setId_Num(int idnum) {this->id_num = idnum;}
	// inline int getArgTotalOffset() { return this->argTotalOffset;}

    //添加数组
    int addArraySymbol(std::string name, int flag);	
};

#endif