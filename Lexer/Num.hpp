#ifndef NUM_HPP
#define NUM_HPP

#include "Token.hpp"

class Num : public Token {
public:
    int value;

    Num(int v);
};

#endif
