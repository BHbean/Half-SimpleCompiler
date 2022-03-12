#ifndef COMPOUNDNODE_H
#define COMPOUNDNODE_H
#include "ASTNode.h"
#include "../symbol/symbol.h"

class CompoundNode : public ASTNode{
private:
    SymbolTable* table;
public:
    CompoundNode(int idx);
    void genNodeInfo();
    int getNodeNum();
    inline SymbolTable* getTable() { return this->table; }
    inline void setTable(SymbolTable* table) { this->table = table; }

};

#endif