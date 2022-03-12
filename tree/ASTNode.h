#ifndef ASTNODE_H
#define ASTNODE_H
#include <iostream>
#include <vector>
#include <string>
#include "../symbol/symbol.h"

enum class ASTNodeType
{
    null = 0,
    defFunc = 1,
    callFunc = 2,
    op = 3,  // 所有运算符
    exp = 4, // 表达式
    typeSpecifier = 5,
    idDcl = 6,
    constDcl = 7,
    varDcl = 8,
    compoudStmt = 9,
    reapeatStmt = 10,
    conditionStmt = 11,
    returnStmt = 12,
    writeFunc = 13,
    readFunc = 14,
    mainFunc = 15,
    program = 16,
    ptrDcl = 17,    // 指针的声明
    arrayDcl = 18   // 数组的声明
};

class ASTNode
{
protected:
    ASTNodeType nodeType;
    ASTNode *parent;
    ASTNode *right_sibling;
    std::vector<ASTNode*>* child;
    int id_num;
    int crosswise_tier;
    std::string node_info;

public:
    ASTNode();
    ASTNode(ASTNodeType nodetype, int id);
    void addChildNode(ASTNode *node);
    static void printTree(ASTNode* node);
    virtual void genNodeInfo();
    std::string getTypeDescription();
    ASTNode* getRightestPeer();
    void printNodeInfo();
    inline int getIndex() { return this->id_num; }
    inline int getCrosswiseTier() { return this->crosswise_tier; }
    inline int getChildNum() { return this->child->size(); }
    inline ASTNode *getParent() { return this->parent; }
    inline ASTNode *getRightSibling() { return this->right_sibling; }
    inline std::vector<ASTNode*>* getChild() { return this->child; }
    inline void setParent(ASTNode *parent) { this->parent = parent; }
    inline void setRightSibling(ASTNode* peer){ this->right_sibling = peer; }
    inline void setIndex(int idx) { this->id_num = idx; }
    inline void setCrosswiseTier(int width) { this->crosswise_tier = width; }
    inline ASTNodeType getNodeType() { return this->nodeType; }
    inline std::string getNodeInfo() { return this->node_info; }
};

#endif