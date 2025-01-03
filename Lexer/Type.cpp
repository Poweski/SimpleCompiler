#include "Type.hpp"
#include <memory>

Type::Type(const std::string& s, int tag, int w) : Word(tag, s), width(w) {}

const std::shared_ptr<Type> Type::Int = std::make_shared<Type>("int", 0, 4);
const std::shared_ptr<Type> Type::Float = std::make_shared<Type>("float", 0, 8);
const std::shared_ptr<Type> Type::Char = std::make_shared<Type>("char", 0, 1);
const std::shared_ptr<Type> Type::Bool = std::make_shared<Type>("bool", 0, 1);

bool Type::numeric(const std::shared_ptr<Type>& p) {
    return p == Type::Char || p == Type::Int || p == Type::Float;
}

std::shared_ptr<Type> Type::max(const std::shared_ptr<Type>& p1, const std::shared_ptr<Type>& p2) {
    if (!numeric(p1) || !numeric(p2)) return nullptr;
    if (p1 == Type::Float || p2 == Type::Float) return Type::Float;
    if (p1 == Type::Int || p2 == Type::Int) return Type::Int;
    return Type::Char;
}

bool operator==(const Type& lhs, const Type& rhs) {
    return lhs.lexeme == rhs.lexeme; 
}