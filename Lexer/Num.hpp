#ifndef NUM_HPP
#define NUM_HPP

#include <cstring>
#include "Token.hpp"

class Num : public Token {
public:
    const int value;

    Num(int v);
    std::string toString();
};

#endif
