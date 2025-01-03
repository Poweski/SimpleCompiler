#ifndef EXPR_HPP
#define EXPR_HPP

#include "Node.hpp"
#include "Token.hpp"
#include "Type.hpp"

class Expr : public Node, public std::enable_shared_from_this<Expr> {
public:
    std::shared_ptr<Token> op;
    std::shared_ptr<Type> type;

    Expr(std::shared_ptr<Token> tok, std::shared_ptr<Type> p);
    virtual std::shared_ptr<Expr> gen();
    virtual std::shared_ptr<Expr> reduce();
    virtual void jumping(int t, int f);
    void emitjumps(const std::string& test, int t, int f);
    virtual std::string toString() const;
};

#endif
