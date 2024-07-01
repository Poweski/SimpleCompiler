#include <iostream>
#include <stdexcept>
#include <cctype>

class Parser {
    static int lookahead;

public:
    Parser() {
        lookahead = std::cin.get();
    }

    void expr() {
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

    void term() {
        if (std::isdigit(lookahead)) {
            std::cout << (char)lookahead;
            match(lookahead);
        } else {
            throw std::runtime_error("Syntax error: expected digit");
        }
    }

    void match(int t) {
        if (lookahead == t) {
            lookahead = std::cin.get();
        } else {
            throw std::runtime_error("Syntax error: unexpected character");
        }
    }
};

int Parser::lookahead = 0;

int main() {
    try {
        Parser parser;
        parser.expr();
        std::cout << "\n";
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
    return 0;
}
