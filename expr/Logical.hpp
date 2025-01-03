#ifndef LOGICAL_HPP
#define LOGICAL_HPP

#include "Expr.hpp"
#include "Token.hpp"
#include "Type.hpp"
#include "Temp.hpp"
#include <memory>
#include <string>

class Logical : public Expr {
public:
    std::shared_ptr<Expr> expr1, expr2;

    Logical(std::shared_ptr<Token> tok, std::shared_ptr<Expr> x1, std::shared_ptr<Expr> x2);

    std::shared_ptr<Type> check(std::shared_ptr<Type> p1, std::shared_ptr<Type> p2);

    std::shared_ptr<Expr> gen() override;

    virtual std::string toString() const override;
};

#endif 
