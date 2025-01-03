#include "Op.hpp"
#include "Temp.hpp"
#include <memory>

Op::Op(std::shared_ptr<Token> tok, std::shared_ptr<Type> p)
    : Expr(tok, p) {}

std::shared_ptr<Expr> Op::reduce() {
    auto x = gen();
    Temp t(type);
    emit(t.toString() + " = " + x->toString());
    return std::make_shared<Temp>(t);
}
