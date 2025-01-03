
#ifndef IF_HPP
#define IF_HPP

#include "Stmt.hpp"
#include "Expr.hpp"

class If : public Stmt {
public:
    If(Expr* x, Stmt* s);
    void gen(int b, int a) override;

private:
    Expr* expr;
    Stmt* stmt;
};

#endif