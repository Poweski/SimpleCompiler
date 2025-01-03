#include "Temp.hpp"
#include <memory>

int Temp::count = 0;

Temp::Temp(std::shared_ptr<Type> p) : Expr(Word::temp, p), number(++count) {}

std::string Temp::toString() const {
    return "t" + std::to_string(number);
}
