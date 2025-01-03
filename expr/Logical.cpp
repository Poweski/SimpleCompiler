#include "Logical.hpp"
#include <stdexcept>

Logical::Logical(std::shared_ptr<Token> tok, std::shared_ptr<Expr> x1, std::shared_ptr<Expr> x2)
    : Expr(tok, nullptr), expr1(x1), expr2(x2) {
    type = check(expr1->type, expr2->type);
    if (type == nullptr) {
        throw std::runtime_error("type error");
    }
}

std::shared_ptr<Type> Logical::check(std::shared_ptr<Type> p1, std::shared_ptr<Type> p2) {
    if (*p1 == *Type::Bool && *p2 == *Type::Bool) {
        return Type::Bool;
    }
    return nullptr;
}

std::shared_ptr<Expr> Logical::gen() {
    int f = newlabel();
    int a = newlabel();
    std::shared_ptr<Temp> temp = std::make_shared<Temp>(type);
    this->jumping(0, f);
    emit(temp->toString() + " = true");
    emit("goto L" + std::to_string(a));
    emitlabel(f);
    emit(temp->toString() + " = false");
    emitlabel(a);
    return temp;
}

std::string Logical::toString() const {
    return expr1->toString() + " " + op->toString() + " " + expr2->toString();
}
