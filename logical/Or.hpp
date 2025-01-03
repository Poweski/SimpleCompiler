#ifndef OR_HPP
#define OR_HPP

#include "Logical.hpp"
#include <memory>

class Or : public Logical {
public:
    Or(std::shared_ptr<Token> tok, std::shared_ptr<Expr> x1, std::shared_ptr<Expr> x2);

    void jumping(int t, int f) override;
};

#endif
