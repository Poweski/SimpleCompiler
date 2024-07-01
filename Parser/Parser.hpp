#ifndef PARSER_HPP
#define PARSER_HPP

#include <iostream>
#include <stdexcept>
#include <cctype>

class Parser {
    static int lookahead;

public:
    Parser();
    void expr();
    void term();
    void match(int t);
};

#endif
