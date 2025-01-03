#include "Rel.hpp"
#include <string>

Rel::Rel(Token tok, Expr* x1, Expr* x2) : Logical(tok, x1, x2) {}

Type* Rel::check(Type* p1, Type* p2) {
    if (dynamic_cast<Array*>(p1) || dynamic_cast<Array*>(p2)) {
        return nullptr;
    } else if (p1 == p2) {
        return Type::Bool;
    } else {
        return nullptr;
    }
}

void Rel::jumping(int t, int f) {
    Expr* a = expr1->reduce();
    Expr* b = expr2->reduce();
    std::string test = a->toString() + " " + op.toString() + " " + b->toString();
    emitjumps(test, t, f);
}
