#include "TypeSpcfNode.h"

TypeSpcfNode::TypeSpcfNode(int idx, std::string type): ASTNode(ASTNodeType::typeSpecifier, idx)
{
    this->type = type;
    this->genNodeInfo();
}

void TypeSpcfNode::genNodeInfo()
{
    this->node_info = this->getTypeDescription() + ":" + std::to_string(this->id_num)
                    + "  " + this->type;
}