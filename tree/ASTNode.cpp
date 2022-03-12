#include "ASTNode.h"

ASTNode::ASTNode()
{
    this->nodeType = ASTNodeType::null;
    this->parent = NULL;
    this->child = new std::vector<ASTNode*>();
    this->right_sibling = NULL;
    this->id_num = -1;
    this->crosswise_tier = 1;
    this->genNodeInfo();
}

ASTNode::ASTNode(ASTNodeType type, int index)
{
    this->nodeType = type;
    this->parent = NULL;
    this->right_sibling = NULL;
    this->child = new std::vector<ASTNode*>();
    this->id_num = index;
    this->crosswise_tier = 1;
    this->genNodeInfo();
}

void ASTNode::addChildNode(ASTNode* node)
{
    if(NULL != node){
        this->child->push_back(node);
        node->setParent(this);
        ASTNode* tmp = node->getRightSibling();
        // std::cout << node->getRightSibling() << std::endl;
        while(NULL != tmp){
            this->child->push_back(tmp);
            tmp->setParent(this);
            tmp = tmp->getRightSibling();
        }
    }
}

ASTNode* ASTNode::getRightestPeer()
{
    ASTNode* target = this;
    if(target->getRightSibling() != NULL){
        ASTNode* tmp = target->getRightSibling();
        while(NULL != tmp){
            target = tmp;
            tmp = tmp->getRightSibling();
        }
    }
    return target;
}

std::string ASTNode::getTypeDescription()
{
    std::string description = "";
    switch (this->nodeType)
    {
    case ASTNodeType::null:{
        description = "Null";
        break;
    }
    case ASTNodeType::defFunc:{
        description = "Function Definition";
        break;
    }
    case ASTNodeType::callFunc:{
        description = "Function Calling";
        break;
    }
    case ASTNodeType::op:{
        description = "Expr";
        break;
    }
    case ASTNodeType::typeSpecifier:{
        description = "Type Specifier";
        break;
    }
    case ASTNodeType::idDcl:{
        description = "ID Declaration";
        break;
    }
    case ASTNodeType::constDcl:{
        description = "Const Declaration";
        break;
    }
    case ASTNodeType::varDcl:{
        description = "Var Declaration";
        break;
    }
    case ASTNodeType::compoudStmt:{
        description = "CompoundK statement";
        break;
    }
    case ASTNodeType::reapeatStmt:{
        description = "RepeatK statement";
        break;
    }
    case ASTNodeType::conditionStmt:{
        description = "Conditional statement";
        break;
    }
    case ASTNodeType::returnStmt:{
        description = "Return statement";
        break;
    }
    case ASTNodeType::writeFunc:{
        description = "WriteK statement";
        break;
    }
    case ASTNodeType::readFunc:{
        description = "ReadK statement";
        break;
    }
    case ASTNodeType::mainFunc:{
        description = "Main Declaration";
        break;
    }
    case ASTNodeType::program:{
        description = "Program";
        break;
    }
    case ASTNodeType::ptrDcl:{
        description = "Pointer Declaration";
        break;
    }
    case ASTNodeType::arrayDcl:{
        description = "Array Declaration";
        break;
    }
    default:
        break;
    }
    return description;
}

void ASTNode::genNodeInfo()
{
    // std::cout << "genarating node info!\n" << std::endl;
    this->node_info = this->getTypeDescription() + ": " + std::to_string(this->id_num);
    // std::cout << "node info genarated!\n" << std::endl;
}

void ASTNode::printNodeInfo()
{
    ASTNode* record = this;
	int tmp_crosswise_gap = record->crosswise_tier;
    int tmp_int = 0;
    std::vector<int> tmp;

	/*观察是否插入 | */
	while (1) {
		
		if (record->parent == NULL) {
			break;
		}
		else {
            tmp.push_back(0);
			record = record->parent;
			if (record->right_sibling != NULL) {
				tmp[tmp_int] = 1;
			}
		}
        tmp_int++;
	}

	for (int i = tmp_crosswise_gap - 2; i>=0; i--) {
		if (tmp[i] == 0) {
			std::cout << "        "; //8个空格
		}
		else {
			std::cout << "│       ";
		}
	}
	if (this->right_sibling == NULL) {
		std::cout << "└" << "───────" << this->node_info << std::endl;
	}
	else {
		std::cout << "├" << "───────" << this->node_info << std::endl;
	}

}

void ASTNode::printTree(ASTNode* node)
{
    if (node == NULL)
	{
		return;
	}
	else {
		//m->lengthways_tier = print_count; //每次打印树结点之前纵向层数加一
		node->printNodeInfo();
        // std::cout << node->getChildNum() << std::endl;
		for (int i = 0; i < node->getChildNum(); i++)		//为指向其孩子结点的指针赋初值
		{
			if (node->child->at(i) != NULL) {
				node->child->at(i)->crosswise_tier = node->crosswise_tier + 1; //子结点的横向层数加一
				ASTNode::printTree(node->child->at(i));
			}
			
		}
	}	
}