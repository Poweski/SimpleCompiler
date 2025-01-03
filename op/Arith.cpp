#include "Arith.hpp"
#include "Type.hpp"
#include <memory>
#include <stdexcept>

Arith::Arith(std::shared_ptr<Token> tok, std::shared_ptr<Expr> x1, std::shared_ptr<Expr> x2)
    : Op(tok, nullptr), expr1(x1), expr2(x2) {
    type = Type::max(expr1->type, expr2->type);
    if (type == nullptr) {
        throw std::runtime_error("type error");
    }
}

std::shared_ptr<Expr> Arith::gen() {
    return std::make_shared<Arith>(op, expr1->reduce(), expr2->reduce());
}

std::string Arith::toString() const {
    return expr1->toString() + " " + op->toString() + " " + expr2->toString();
}
