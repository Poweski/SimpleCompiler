#include "Break.hpp"

Break::Break() {
    if (Stmt::Enclosing == nullptr) {
        error("unenclosed break");
    }
    stmt = Stmt::Enclosing;
}

void Break::gen(int b, int a) {
    emit("goto L" + std::to_string(stmt->after));
}
