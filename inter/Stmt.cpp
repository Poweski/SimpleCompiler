#include "Stmt.hpp"

Stmt* Stmt::Null = new Stmt();
Stmt* Stmt::Enclosing = Stmt::Null;

Stmt::Stmt() : after(0) {}

void Stmt::gen(int b, int a) {}
