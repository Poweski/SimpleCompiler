#ifndef REL_HPP
#define REL_HPP

#include "Logical.hpp"
#include "Type.hpp"
#include "Expr.hpp"

class Rel : public Logical {
public:
    Rel(Token tok, Expr* x1, Expr* x2);
    Type* check(Type* p1, Type* p2);
    void jumping(int t, int f);
};

#endif