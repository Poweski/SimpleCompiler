#ifndef STMT_HPP
#define STMT_HPP

#include "Node.hpp"

class Stmt : public Node {
public:    
    static Stmt* Enclosing;
    static Stmt* Null;
    int after;

    Stmt();
    virtual void gen(int b, int a);
};

#endif