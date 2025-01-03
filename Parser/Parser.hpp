#ifndef PARSER_HPP
#define PARSER_HPP

#include "Env.hpp"
#include "Lexer.hpp"
#include "Stmt.hpp"
#include "Expr.hpp"
#include "Token.hpp"
#include "Type.hpp"
#include "Array.hpp"
#include "Id.hpp"
#include "Access.hpp"
#include "Constant.hpp"
#include "Unary.hpp"
#include "Rel.hpp"
#include "Arith.hpp"
#include "And.hpp"
#include "Or.hpp"
#include "Break.hpp"
#include "While.hpp"
#include "Do.hpp"
#include "Seq.hpp"
#include "If.hpp"
#include "Else.hpp"

class Parser {
private:
    Lexer& lex;
    Token look;
    Env* top = nullptr;
    int used = 0;

    void move();
    void error(const std::string& s);
    void match(int t);
    Stmt block();
    void decls();
    Type type();
    Type dims(Type p);
    Stmt stmts();
    Stmt stmt();
    Stmt assign();
    Expr boolExpr();
    Expr join();
    Expr equality();
    Expr rel();
    Expr expr();
    Expr term();
    Expr unary();
    Expr factor();
    Access offset(Id a);

public:
    explicit Parser(Lexer& l);
    void program();
};

#endif // PARSER_HPP
