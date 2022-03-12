#ifndef TYPESPCFNODE_H
#define TYPESPCFNODE_H
#include "ASTNode.h"

class TypeSpcfNode : public ASTNode{
private:
    std::string type;
public:
    TypeSpcfNode(int idx, std::string type);
    void genNodeInfo();
    inline std::string getType() { return this->type; }
    inline void setType(std::string str) { this->type = str; }
};

#endif