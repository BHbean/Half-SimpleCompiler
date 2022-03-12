#ifndef REPEATNODE_H
#define REPEATNODE_H
#include "ASTNode.h"

class RepeatNode : public ASTNode{
private:
    std::string head;
public:
    RepeatNode(int idx, std::string type);
    void genNodeInfo();
    inline std::string getHead() { return this->head; }
    inline void setHead(std::string str) { this->head = str; }
};

#endif