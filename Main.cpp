#include <iostream>
#include "Parser\Parser.hpp"
#include "Lexer\Lexer.hpp"

int main() {
    // try {
    //     Parser parser;
    //     parser.expr();
    //     std::cout << "\n";
    // } catch (const std::exception& e) {
    //     std::cerr << "Error: " << e.what() << std::endl;
    // }

    Lexer lexer;
    Token* token;
    
    while ((token = lexer.scan()) != nullptr) {
        std::cout << "Token tag: " << token->tag << std::endl;
        delete token;
    }

    return 0;
}
