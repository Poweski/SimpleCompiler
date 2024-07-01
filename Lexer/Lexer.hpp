#ifndef LEXER_HPP
#define LEXER_HPP

#include <iostream>
#include <unordered_map>
#include <cctype>
#include <string>
#include "Token.hpp"
#include "Word.hpp"
#include "Num.hpp"

class Lexer {
public:
    int line = 1;
    char peek = ' ';
    std::unordered_map<std::string, Word> words;

    void reserve(const Word& t);

    Lexer();

    Token* scan();
};

#endif
