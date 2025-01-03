#ifndef DO_HPP
#define DO_HPP

#include "Stmt.hpp"
#include "Expr.hpp"
#include "Type.hpp"

class Do : public Stmt {
private:
    Expr* expr;
    Stmt* stmt;

public:
    Do();
    void init(Expr* x, Stmt* s);
    void gen(int b, int a) override;
};

#endif