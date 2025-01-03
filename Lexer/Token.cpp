#include "Token.hpp"

Token::Token(int t) : tag(t) {}

std::string Token::toString() {
    return std::to_string(tag);
}

std::size_t TokenHash::operator()(const Token& token) const {
    return std::hash<int>{}(token.tag);
}