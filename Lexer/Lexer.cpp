#include "Lexer.hpp"

void Lexer::reserve(const Word& t) {
    words[t.lexeme] = t;
}

Lexer::Lexer() {
    reserve(Word(Tag::True, "true"));
    reserve(Word(Tag::False, "false"));
}

Token* Lexer::scan() {
    for (;;) {
        while (isspace(peek)) {
            if (peek == '\n') line++;
            peek = std::cin.get();
        }

        if (isdigit(peek)) {
            int v = 0;
            do {
                v = 10 * v + (peek - '0');
                peek = std::cin.get();
            } while (isdigit(peek));
            return new Num(v);
        }

        if (isalpha(peek)) {
            std::string b;
            do {
                b += peek;
                peek = std::cin.get();
            } while (isalnum(peek));
            std::string s = b;
            auto it = words.find(s);
            if (it != words.end()) {
                return new Word(it->second.tag, it->second.lexeme);
            } else {
                Word w(Tag::ID, s);
                words[s] = w;
                return new Word(Tag::ID, s);
            }
        }

        Token* t = new Token(peek);
        peek = ' ';
        return t;
    }
}
