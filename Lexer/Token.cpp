#include "Token.hpp"

Token::Token(int t) : tag(t) {}

std::string Token::toString() {
    return std::to_string(tag);
}
