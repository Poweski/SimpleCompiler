#include "Not.hpp"

Not::Not(std::shared_ptr<Token> tok, std::shared_ptr<Expr> x2)
    : Logical(tok, x2, x2) {}

void Not::jumping(int t, int f) {
    expr2->jumping(f, t);
}

std::string Not::toString() const {
    return op->toString() + " " + expr2->toString();
}
