#ifndef SEQ_HPP
#define SEQ_HPP

#include "Stmt.hpp"

class Seq : public Stmt {
public:
    Stmt* stmt1;
    Stmt* stmt2;

    Seq(Stmt* s1, Stmt* s2);

    void gen(int b, int a) override;
};

#endif
