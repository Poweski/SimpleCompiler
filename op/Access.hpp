#ifndef ACCESS_HPP
#define ACCESS_HPP

#include "Op.hpp"
#include "Id.hpp"
#include "Expr.hpp"
#include "Word.hpp"

class Access : public Op {
public:
    Id* array;
    Expr* index;

    Access(Id* a, Expr* i, Type* p);
    
    std::shared_ptr<Expr> gen();
    void jumping(int t, int f);
    std::string toString() const;
};

#endif
