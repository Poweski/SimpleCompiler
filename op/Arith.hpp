#ifndef ARITH_HPP
#define ARITH_HPP

#include "Op.hpp"
#include "Expr.hpp"
#include "Token.hpp"
#include "Type.hpp"

class Arith : public Op {
public:
    std::shared_ptr<Expr> expr1, expr2;

    Arith(std::shared_ptr<Token> tok, std::shared_ptr<Expr> x1, std::shared_ptr<Expr> x2);

    std::shared_ptr<Expr> gen() override;

    std::string toString() const override;
};

#endif
