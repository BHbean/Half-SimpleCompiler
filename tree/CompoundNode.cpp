#include "CompoundNode.h"

CompoundNode::CompoundNode(int idx): ASTNode(ASTNodeType::compoudStmt, idx)
{
    this->table = new SymbolTable();
    this->table->setId_Num(this->id_num);
    this->genNodeInfo();
    std::cout<<"                                                "<<this->table->getId_Num()<<std::endl;
}

void CompoundNode::genNodeInfo()
{
    this->node_info = this->getTypeDescription() + ":" + std::to_string(this->id_num);
}

int CompoundNode::getNodeNum()
{
   return this->id_num; 
}