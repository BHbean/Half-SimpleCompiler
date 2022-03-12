#include "IdDeclarationNode.h"

IdDeclarationNode::IdDeclarationNode(int idx, std::string identifier): ASTNode(ASTNodeType::idDcl, idx)
{
    this->identifier = identifier;
    this->genNodeInfo();
    this->symbol = new Symbol(identifier, SymbolType::integer);
}

void IdDeclarationNode::genNodeInfo()
{
    this->node_info = this->getTypeDescription() + ":" + std::to_string(this->id_num)
                    + "  " + this->identifier;
}