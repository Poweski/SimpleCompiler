#include "Parser.hpp"

int Parser::lookahead = 0;

Parser::Parser() {
    lookahead = std::cin.get();
}

void Parser::expr() {
    term();
    while (true) {
        if (lookahead == '+') {
            match('+');
            term();
            std::cout << '+';
        } else if (lookahead == '-') {
            match('-');
            term();
            std::cout << '-';
        } else {
            return;
        }
    }
}

void Parser::term() {
    if (std::isdigit(lookahead)) {
        std::cout << (char)lookahead;
        match(lookahead);
    } else {
        throw std::runtime_error("Syntax error: expected digit");
    }
}

void Parser::match(int t) {
    if (lookahead == t) {
        lookahead = std::cin.get();
    } else {
        throw std::runtime_error("Syntax error: unexpected character");
    }
}
