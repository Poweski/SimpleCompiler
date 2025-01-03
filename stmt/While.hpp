#ifndef WHILE_HPP
#define WHILE_HPP

#include "Stmt.hpp"
#include "Expr.hpp"
#include "Type.hpp"

class While : public Stmt {
private:
    Expr* expr;
    Stmt* stmt;

public:
    While();
    void init(Expr* x, Stmt* s);
    void gen(int b, int a) override;
};

#endif