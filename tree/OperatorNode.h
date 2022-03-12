#ifndef OPERATORNODE_H
#define OPERATORNODE_H
#include "ASTNode.h"

class OperatorNode: public ASTNode{
private:
    std::string op;
    bool isConstExpr;
public:
    OperatorNode(int idx, std::string op);
    ~OperatorNode();
    void genNodeInfo();
    inline std::string getOp() { return this->op; }
    inline void setOp(std::string str) { this->op = str; }
    // 获取判断常数表达式的标记
    inline bool getFlag() { return this->isConstExpr; }
    inline void setFlag(bool flag) { this->isConstExpr = flag; }
};


#endif