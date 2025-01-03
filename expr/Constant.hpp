#ifndef CONSTANT_HPP
#define CONSTANT_HPP

#include "Expr.hpp"
#include "Token.hpp"
#include "Type.hpp"
#include "Word.hpp"
#include <memory>
#include <string>

class Constant : public Expr {
public:
    Constant(std::shared_ptr<Token> tok, std::shared_ptr<Type> p);

    Constant(int i);

    static const std::shared_ptr<Constant> True;
    static const std::shared_ptr<Constant> False;

    void jumping(int t, int f) override;
};

bool operator==(const Constant& lhs, const Constant& rhs);

bool operator==(const std::shared_ptr<Constant>& lhs, const std::shared_ptr<Constant>& rhs);

#endif
