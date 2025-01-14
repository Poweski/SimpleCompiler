#include "Set.hpp"

Set::Set(Id* i, Expr* x) : id(i), expr(x) {
    if (check(id->type, expr->type) == nullptr) {
        error("type error");
    }
}

Type* Set::check(Type* p1, Type* p2) {
    if (Type::numeric(p1) && Type::numeric(p2)) {
        return p2;
    } else if (p1 == Type::Bool && p2 == Type::Bool) {
        return p2;
    } else {
        return nullptr;
    }
}

void Set::gen(int b, int a) {
    emit(id->toString() + " " + expr->gen()->toString());
}
