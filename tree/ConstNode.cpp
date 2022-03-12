#include "ConstNode.h"

ConstNode::ConstNode(int idx, int val): ASTNode(ASTNodeType::constDcl, idx)
{
    this->value = val;
    this->genNodeInfo();
}

void ConstNode::genNodeInfo()
{
    this->node_info = this->getTypeDescription() + ":" + std::to_string(this->id_num)
                    + "  " + std::to_string(this->value);
}