#ifndef WORD_HPP
#define WORD_HPP

#include <string>
#include "Token.hpp"

class Word : public Token {
public:
    std::string lexeme;
    static const Word and, or, eq, ne, le, ge, minus, True, False, temp;

    Word() : Token(Tag::TEMP), lexeme("") {}
    Word(int t, const std::string& s);
    std::string toString();
};

#endif
