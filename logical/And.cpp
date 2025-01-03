#include "And.hpp"

And::And(std::shared_ptr<Token> tok, std::shared_ptr<Expr> x1, std::shared_ptr<Expr> x2)
    : Logical(tok, x1, x2) {}

void And::jumping(int t, int f) {
    int label = (f != 0) ? f : newlabel();
    expr1->jumping(0, label);
    expr2->jumping(t, f);
    if (f == 0) emitlabel(label);
}
