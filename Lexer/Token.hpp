#ifndef TOKEN_HPP
#define TOKEN_HPP

#include <string>
#include "Tag.hpp"

class Token {
public:
    int tag;

    Token(int t);
    std::string toString();
};

#endif
