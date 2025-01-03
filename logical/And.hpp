#ifndef AND_HPP
#define AND_HPP

#include "Logical.hpp"
#include <memory>

class And : public Logical {
public:
    And(std::shared_ptr<Token> tok, std::shared_ptr<Expr> x1, std::shared_ptr<Expr> x2);

    void jumping(int t, int f) override;
};

#endif
