#ifndef LEXER_HPP
#define LEXER_HPP

#include <string>
#include <unordered_map>
#include <memory>
#include <iostream>
#include "Token.hpp"
#include "Word.hpp"
#include "Tag.hpp"
#include "Num.hpp"
#include "Real.hpp"

class Lexer {
public:
    static int line;
    char peek = ' ';
    std::unordered_map<std::string, std::shared_ptr<Word>> words;

    Lexer();
    void reserve(std::shared_ptr<Word> w);
    void readch();
    bool readch(char c);
    std::shared_ptr<Token> scan();
};

#endif
