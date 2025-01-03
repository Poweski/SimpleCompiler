
#include "Do.hpp"
#include <iostream>

Do::Do() : expr(nullptr), stmt(nullptr) {}

void Do::init(Expr* x, Stmt* s) {
    expr = x;
    stmt = s;
    if (expr->type != Type::Bool) {
        expr->error("boolean required in do");
    }
}

void Do::gen(int b, int a) {
    after = a;   
    int label = newlabel();
    stmt->gen(b, label);
    emitlabel(label);
    expr->jumping(b, 0);
}
