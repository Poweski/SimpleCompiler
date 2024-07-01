#ifndef WORD_HPP
#define WORD_HPP

#include <string>
#include "Token.hpp"

class Word : public Token {
public:
    std::string lexeme;

    Word() : Token(0), lexeme("") {}
    Word(int t, const std::string& s);
};

#endif
