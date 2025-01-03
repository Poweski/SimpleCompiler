#include "Or.hpp"

Or::Or(std::shared_ptr<Token> tok, std::shared_ptr<Expr> x1, std::shared_ptr<Expr> x2)
    : Logical(tok, x1, x2) {}

void Or::jumping(int t, int f) {
    int label = (t != 0) ? t : newlabel();
    expr1->jumping(label, 0);
    expr2->jumping(t, f);
    if (t == 0) emitlabel(label);
}
