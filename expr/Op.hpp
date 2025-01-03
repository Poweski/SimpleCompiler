#ifndef OP_HPP
#define OP_HPP

#include "Expr.hpp"
#include "Token.hpp"
#include "Type.hpp"
#include "Temp.hpp"

class Op : public Expr {
public:
    Op(std::shared_ptr<Token> tok, std::shared_ptr<Type> p);

    std::shared_ptr<Expr> reduce() override;
};

#endif
