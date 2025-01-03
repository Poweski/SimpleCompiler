#include "Constant.hpp"
#include "Num.hpp"
#include <stdexcept>

const std::shared_ptr<Constant> Constant::True = std::make_shared<Constant>(Word::True, Type::Bool);
const std::shared_ptr<Constant> Constant::False = std::make_shared<Constant>(Word::False, Type::Bool);

Constant::Constant(std::shared_ptr<Token> tok, std::shared_ptr<Type> p)
    : Expr(tok, p) {}

Constant::Constant(int i)
    : Expr(std::make_shared<Num>(i), Type::Int) {}

void Constant::jumping(int t, int f) {
    if (this == Constant::True && t != 0) {
        emit("goto L" + std::to_string(t));
    }
    else if (this == Constant::False && f != 0) {
        emit("goto L" + std::to_string(f));
    }
}

bool operator==(const Constant& lhs, const Constant& rhs) {
    return lhs.op == rhs.op; 
}

bool operator==(const Constant* lhs, const std::shared_ptr<Constant>& rhs) {
    if (lhs == nullptr || rhs == nullptr) {
        return false;
    }
    return *lhs == *rhs;
}
