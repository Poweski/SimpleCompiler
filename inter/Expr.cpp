#include "Expr.hpp"
#include <iostream>
#include <memory>

Expr::Expr(std::shared_ptr<Token> tok, std::shared_ptr<Type> p)
    : op(tok), type(p) {}

std::shared_ptr<Expr> Expr::gen() {
    return shared_from_this();
}

std::shared_ptr<Expr> Expr::reduce() {
    return shared_from_this();
}

void Expr::jumping(int t, int f) {
    emitjumps(toString(), t, f);
}

void Expr::emitjumps(const std::string& test, int t, int f) {
    if (t != 0 && f != 0) {
        emit("if " + test + " goto L" + std::to_string(t));
        emit("goto L" + std::to_string(f));
    } else if (t != 0) {
        emit("if " + test + " goto L" + std::to_string(t));
    } else if (f != 0) {
        emit("iffalse " + test + " goto L" + std::to_string(f));
    }
}

std::string Expr::toString() const {
    return op->toString();
}
