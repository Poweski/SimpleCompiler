#include "Num.hpp"

Num::Num(int v) : Token(Tag::NUM), value(v) {}

std::string Num::toString() {
    return std::to_string(value);
}
