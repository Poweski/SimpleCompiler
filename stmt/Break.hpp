#ifndef BREAK_HPP
#define BREAK_HPP

#include "Stmt.hpp"

class Break : public Stmt {
public:
    Stmt* stmt;

    Break();

    void gen(int b, int a) override;
};

#endif
