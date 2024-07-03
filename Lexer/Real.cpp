#include "Real.hpp"

Real::Real(float v) : Token(Tag::REAL), value(v) {}

std::string Real::toString() {
    return std::to_string(value);
}
