#include "SetElem.hpp"
#include "Type.hpp"
#include "Array.hpp"

SetElem::SetElem(Access* x, Expr* y)
    : array(x->array), index(x->index), expr(y) {
    if (check(x->type, expr->type) == nullptr) {
        error("type error");
    }
}

Type* SetElem::check(Type* p1, Type* p2) {
    if (dynamic_cast<Array*>(p1) || dynamic_cast<Array*>(p2)) {
        return nullptr;
    } else if (p1 == p2) {
        return p2;
    } else if (Type::numeric(p1) && Type::numeric(p2)) {
        return p2;
    } else {
        return nullptr;
    }
}

void SetElem::gen(int b, int a) {
    std::string s1 = index->reduce()->toString();
    std::string s2 = expr->reduce()->toString();
    emit(array->toString() + " [ " + s1 + " ] = " + s2);
}
