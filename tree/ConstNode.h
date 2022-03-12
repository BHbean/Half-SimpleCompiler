#ifndef CONSTNODE_H
#define CONSTNODE_H
#include "ASTNode.h"

class ConstNode : public ASTNode{
private:
    int value;
public:
    ConstNode(int idx, int val);
    void genNodeInfo();
    inline int getValue() { return this->value; }
    inline void setValue(int val) { this->value = val; }
};

#endif