#include <iostream>
#include "Parser\Parser.hpp"
#include "Lexer\Lexer.hpp"

int main() 
{           
    Parser parser;
    Lexer lexer;
    Token* token;

    try 
    {
        parser.expr();
        std::cout << "\n";
    } 
    catch (const std::exception& e) 
    {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}
