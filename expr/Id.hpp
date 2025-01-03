#ifndef ID_HPP
#define ID_HPP

#include "Expr.hpp"
#include "Word.hpp"
#include "Type.hpp"

class Id : public Expr {
public:
    int offset;
    
    Id(Word id, Type p, int b);

    virtual ~Id() = default;
};

#endif
