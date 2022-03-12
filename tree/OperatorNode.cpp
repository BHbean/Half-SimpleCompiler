#include "OperatorNode.h"

OperatorNode::OperatorNode(int idx, std::string op): ASTNode(ASTNodeType::op, idx)
{
    this->op = op;
    this->isConstExpr = false;
    this->genNodeInfo();
}

OperatorNode::~OperatorNode()
{
}

void OperatorNode::genNodeInfo()
{
    this->node_info = this->getTypeDescription() + ":" + std::to_string(this->id_num)
                    + "  " + this->op;
}