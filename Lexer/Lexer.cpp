#include "Lexer.hpp"
#include <cctype>
#include <sstream>

int Lexer::line = 1;

Lexer::Lexer() 
{
    reserve(std::make_shared<Word>("if", Tag::IF));
    reserve(std::make_shared<Word>("else", Tag::ELSE));
    reserve(std::make_shared<Word>("while", Tag::WHILE));
    reserve(std::make_shared<Word>("do", Tag::DO));
    reserve(std::make_shared<Word>("break", Tag::BREAK));
    reserve(Word::True);
    reserve(Word::False);
    reserve(Word::Int);
    reserve(Word::Char);
    reserve(Word::Bool);
    reserve(Word::Float);
}

void Lexer::reserve(std::shared_ptr<Word> w) 
{
    words[w->lexeme] = w;
}

void Lexer::readch() 
{
    peek = std::cin.get();
}

bool Lexer::readch(char c) 
{
    readch();
    if (peek != c) 
        return false;
    peek = ' ';
    return true;
}

std::shared_ptr<Token> Lexer::scan() 
{
    for (;; readch()) 
    {
        if (peek == ' ' || peek == '\t') 
            continue;
        else if (peek == '\n') 
            ++line;
        else 
            break;
    }

    switch (peek) 
    {
    case '&':
        if (readch('&')) return Word::And; else return std::make_shared<Token>('&');
    case '|':
        if (readch('|')) return Word::Or; else return std::make_shared<Token>('|');
    case '=':
        if (readch('=')) return Word::Eq; else return std::make_shared<Token>('=');
    case '!':
        if (readch('=')) return Word::Ne; else return std::make_shared<Token>('!');
    case '<':
        if (readch('=')) return Word::Le; else return std::make_shared<Token>('<');
    case '>':
        if (readch('=')) return Word::Ge; else return std::make_shared<Token>('>');
    }

    if (std::isdigit(peek)) 
    {
        int v = 0;

        do 
        {
            v = 10 * v + (peek - '0');
            readch();
        } 
        while (std::isdigit(peek));

        if (peek != '.') 
            return std::make_shared<Num>(v);

        float x = v;
        float d = 10;

        for (;;) 
        {
            readch();
            if (!std::isdigit(peek)) 
                break;
            x = x + (peek - '0') / d;
            d *= 10;
        }
        return std::make_shared<Real>(x);
    }

    if (std::isalpha(peek)) 
    {
        std::ostringstream buffer;

        do 
        {
            buffer << peek;
            readch();
        } 
        while (std::isalnum(peek));

        std::string s = buffer.str();
        auto it = words.find(s);

        if (it != words.end()) 
            return it->second;

        auto w = std::make_shared<Word>(s, Tag::ID);
        words[s] = w;
        return w;
    }

    auto tok = std::make_shared<Token>(peek);
    peek = ' ';
    return tok;
}
