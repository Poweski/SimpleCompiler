#ifndef NODE_HPP
#define NODE_HPP

#include <string>
#include <stdexcept>
#include <iostream>
#include "Lexer.hpp"

class Node {
public:
    int lexline;

    Node();

    void error(const std::string& s);

    static int labels;
    int newlabel();
    void emitlabel(int i);
    void emit(const std::string& s);
};

#endif
