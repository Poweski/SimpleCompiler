#ifndef SETELEM_HPP
#define SETELEM_HPP

#include "Stmt.hpp"
#include "Id.hpp"
#include "Expr.hpp"
#include "Access.hpp"

class SetElem : public Stmt {
public:
    Id* array;
    Expr* index;
    Expr* expr;

    SetElem(Access* x, Expr* y);

    Type* check(Type* p1, Type* p2);
    void gen(int b, int a);
};

#endif
