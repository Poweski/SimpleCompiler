#include "Parser.hpp"
#include <stdexcept>
#include <iostream>

Parser::Parser(Lexer& l) : lex(l) {
    move();
}

void Parser::move() {
    look = lex.scan();
}

void Parser::error(const std::string& s) {
    throw std::runtime_error("near line " + std::to_string(lex.line()) + ": " + s);
}

void Parser::match(int t) {
    if (look.tag == t) {
        move();
    } else {
        error("syntax error");
    }
}

void Parser::program() {
    Stmt s = block();
    int begin = s.newlabel();
    int after = s.newlabel();
    s.emitlabel(begin);
    s.gen(begin, after);
    s.emitlabel(after);
}

Stmt Parser::block() {
    match('{');
    Env* savedEnv = top;
    top = new Env(top);
    decls();
    Stmt s = stmts();
    match('}');
    top = savedEnv;
    return s;
}

void Parser::decls() {
    while (look.tag == Tag::BASIC) {
        Type p = type();
        Token tok = look;
        match(Tag::ID);
        match(';');
        Id id(tok, p, used);
        top->put(tok, id);
        used += p.width;
    }
}

Type Parser::type() {
    Type p = static_cast<Type>(look);
    match(Tag::BASIC);
    if (look.tag != '[') return p;
    else return dims(p);
}

Type Parser::dims(Type p) {
    match('[');
    Token tok = look;
    match(Tag::NUM);
    match(']');
    if (look.tag == '[') p = dims(p);
    return Array(static_cast<Num>(tok).value, p);
}

Stmt Parser::stmts() {
    if (look.tag == '}') return Stmt::Null;
    else return Seq(stmt(), stmts());
}

Stmt Parser::stmt() {
    Expr x;
    Stmt s, s1, s2;
    Stmt savedStmt;

    switch (look.tag) {
        case ';': // Puste wyrażenie (np. samotny średnik)
            move();
            return Stmt::Null;

        case Tag::IF: { // Instrukcja warunkowa
            match(Tag::IF);
            match('(');
            x = boolExpr();
            match(')');
            s1 = stmt();
            if (look.tag != Tag::ELSE) {
                return If(x, s1);
            }
            match(Tag::ELSE);
            s2 = stmt();
            return Else(x, s1, s2);
        }

        case Tag::WHILE: { // Pętla WHILE
            While* whilenode = new While();
            savedStmt = Stmt::Enclosing;
            Stmt::Enclosing = whilenode;
            match(Tag::WHILE);
            match('(');
            x = boolExpr();
            match(')');
            s1 = stmt();
            whilenode->init(x, s1);
            Stmt::Enclosing = savedStmt;
            return *whilenode;
        }

        case Tag::DO: { // Pętla DO-WHILE
            Do* donode = new Do();
            savedStmt = Stmt::Enclosing;
            Stmt::Enclosing = donode;
            match(Tag::DO);
            s1 = stmt();
            match(Tag::WHILE);
            match('(');
            x = boolExpr();
            match(')');
            match(';');
            donode->init(s1, x);
            Stmt::Enclosing = savedStmt;
            return *donode;
        }

        case Tag::BREAK: { // Instrukcja BREAK
            match(Tag::BREAK);
            match(';');
            if (Stmt::Enclosing == nullptr) {
                error("unenclosed break");
            }
            return Break();
        }

        case '{': // Blok instrukcji
            return block();

        default: // Domyślny przypadek: przypisanie
            return assign();
    }
}

Stmt Parser::assign() {
    Token t = look;
    match(Tag::ID);
    Id id = top->get(t);
    if (!id) error(t.toString() + " undeclared");
    if (look.tag == '=') {
        move();
        return Set(id, boolExpr());
    } else {
        Access x = offset(id);
        match('=');
        return SetElem(x, boolExpr());
    }
    match(';');
    return stmt;
}

Expr Parser::boolExpr() {
    Expr x = join();
    while (look.tag == Tag::OR) {
        Token tok = look;
        move();
        x = Or(tok, x, join());
    }
    return x;
}

Expr Parser::join() {
    Expr x = equality();
    while (look.tag == Tag::AND) {
        Token tok = look;
        move();
        x = And(tok, x, equality());
    }
    return x;
}

Expr Parser::equality() {
    Expr x = rel();
    while (look.tag == Tag::EQ || look.tag == Tag::NE) {
        Token tok = look;
        move();
        x = Rel(tok, x, rel());
    }
    return x;
}

Expr Parser::rel() {
    Expr x = expr();
    switch (look.tag) {
        case '<':
        case Tag::LE:
        case Tag::GE:
        case '>': {
            Token tok = look;
            move();
            return Rel(tok, x, expr());
        }
        default:
            return x;
    }
}

Expr Parser::expr() {
    Expr x = term();
    while (look.tag == '+' || look.tag == '-') {
        Token tok = look;
        move();
        x = Arith(tok, x, term());
    }
    return x;
}

Expr Parser::term() {
    Expr x = unary();
    while (look.tag == '*' || look.tag == '/') {
        Token tok = look;
        move();
        x = Arith(tok, x, unary());
    }
    return x;
}

Expr Parser::unary() {
    if (look.tag == '-') {
        move();
        return Unary(Word::minus, unary());
    } else if (look.tag == '!') {
        Token tok = look;
        move();
        return Not(tok, unary());
    } else {
        return factor();
    }
}

Expr Parser::factor() {
    Expr x = nullptr;
    switch (look.tag) {
        case '(':
            move();
            x = boolExpr();
            match(')');
            return x;
        case Tag::NUM:
            x = Constant(look, Type::Int);
            move();
            return x;
        case Tag::REAL:
            x = Constant(look, Type::Float);
            move();
            return x;
        case Tag::TRUE:
            x = Constant::True;
            move();
            return x;
        case Tag::FALSE:
            x = Constant::False;
            move();
            return x;
        case Tag::ID: {
            std::string s = look.toString();
            Id id = top->get(look);
            if (!id) error(look.toString() + " undeclared");
            move();
            if (look.tag != '[') return id;
            else return offset(id);
        }
        default:
            error("syntax error");
            return x;
    }
}

Access Parser::offset(Id a) {
    Expr i, w, t1, t2, loc;
    Type type = a.type;
    match('[');
    i = boolExpr();
    match(']');
    type = static_cast<Array&>(type).of;
    w = Constant(type.width);
    t1 = Arith(Token('*'), i, w);
    loc = t1;

    while (look.tag == '[') {
        match('[');
        i = boolExpr();
        match(']');
        type = static_cast<Array&>(type).of;
        w = Constant(type.width);
        t1 = Arith(Token('*'), i, w);
        t2 = Arith(Token('+'), loc, t1);
        loc = t2;
    }
    return Access(a, loc, type);
}
