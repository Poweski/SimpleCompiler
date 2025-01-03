#include "Unary.hpp"
#include <stdexcept>

Unary::Unary(std::shared_ptr<Token> tok, std::shared_ptr<Expr> x)
    : Op(tok, nullptr), expr(x) {
    type = Type::max(Type::Int(), expr->type);
    if (type == nullptr) {
        throw std::runtime_error("type error");
    }
}

std::shared_ptr<Expr> Unary::gen() {
    return std::make_shared<Unary>(op, expr->reduce());
}

std::string Unary::toString() const {
    return op->toString() + " " + expr->toString();
}
