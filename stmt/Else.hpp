
#ifndef ELSE_HPP
#define ELSE_HPP

#include "Stmt.hpp"
#include "Expr.hpp"

class Else : public Stmt {
public:
    Else(Expr* x, Stmt* s1, Stmt* s2);
    void gen(int b, int a) override;

private:
    Expr* expr;
    Stmt* stmt1;
    Stmt* stmt2;
};

#endif