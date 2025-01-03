#ifndef TEMP_HPP
#define TEMP_HPP

#include "Expr.hpp"
#include "Type.hpp"
#include "Word.hpp"
#include <string>

class Temp : public Expr {
public:
    static int count;
    int number;

    Temp(std::shared_ptr<Type> p);

    std::string toString() const override;
};

#endif
