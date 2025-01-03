#ifndef NOT_HPP
#define NOT_HPP

#include "Logical.hpp"
#include <memory>

class Not : public Logical {
public:
    Not(std::shared_ptr<Token> tok, std::shared_ptr<Expr> x2);

    void jumping(int t, int f) override;

    std::string toString() const override;
};

#endif
