#include "RepeatNode.h"

RepeatNode::RepeatNode(int idx, std::string head): ASTNode(ASTNodeType::reapeatStmt, idx)
{
    this->head = head;
    this->genNodeInfo();
}

void RepeatNode::genNodeInfo()
{
    this->node_info = this->getTypeDescription() + ":" + std::to_string(this->id_num)
                    + "  " + this->head;
}