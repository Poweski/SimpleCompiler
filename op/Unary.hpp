#ifndef UNARY_HPP
#define UNARY_HPP

#include "Op.hpp"
#include "Expr.hpp"
#include "Token.hpp"
#include "Type.hpp"
#include <memory>
#include <string>

class Unary : public Op {
public:
    std::shared_ptr<Expr> expr;

    Unary(std::shared_ptr<Token> tok, std::shared_ptr<Expr> x);

    std::shared_ptr<Expr> gen() override;

    std::string toString() const override;
};

#endif
