#ifndef SET_HPP
#define SET_HPP

#include "Stmt.hpp"
#include "Expr.hpp"
#include "Type.hpp"
#include "Id.hpp"

class Set : public Stmt {
public:
    Id* id;
    Expr* expr;

    Set(Id* i, Expr* x);
    Type* check(Type* p1, Type* p2);
    void gen(int b, int a) override;
};

#endif 