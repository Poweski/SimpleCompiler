#ifndef REAL_HPP
#define REAL_HPP

#include <string>
#include "Token.hpp"

class Real : public Token {
public:
    const float value;

    Real(float v);
    std::string toString();
};

#endif
