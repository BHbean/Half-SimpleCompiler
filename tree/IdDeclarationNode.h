#ifndef IDDECLARATIONNODE_H
#define IDDECLARATIONNODE_H
#include "ASTNode.h"

class IdDeclarationNode : public ASTNode{
private:
    std::string identifier;
    Symbol * symbol;
public:
    IdDeclarationNode(int idx, std::string identifier);
    void genNodeInfo();
    inline std::string getIdentifier() { return this->identifier; }
    inline SymbolType getSymbolType() { return this->symbol->getType();}
    inline Symbol * getSymbol() {return this->symbol;}
    inline void setIdentifier(std::string str) { this->identifier = str; }
};

#endif