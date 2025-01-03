#ifndef TOKEN_HPP
#define TOKEN_HPP

#include <string>
#include "Tag.hpp"

class Token {
public:
    const int tag;

    Token(int t);
    std::string toString();
};

struct TokenHash {
    std::size_t operator()(const Token& token) const;
};

#endif
