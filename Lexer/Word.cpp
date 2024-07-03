#include "Word.hpp"

const Word Word::and = Word(Tag::AND, "&&");
const Word Word::or = Word(Tag::OR, "||");
const Word Word::eq = Word(Tag::EQ, "==");
const Word Word::ne = Word(Tag::NE, "!=");
const Word Word::le = Word(Tag::LE, "<=");
const Word Word::ge = Word(Tag::GE, ">=");
const Word Word::minus = Word(Tag::MINUS, "minus");
const Word Word::True = Word(Tag::TRUE, "true");
const Word Word::False = Word(Tag::FALSE, "false");
const Word Word::temp = Word(Tag::TEMP, "t");

Word::Word(int t, const std::string& s) : Token(t), lexeme(s) {}

std::string Word::toString() {
    return lexeme;
}
