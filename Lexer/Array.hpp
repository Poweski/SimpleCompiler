#ifndef ARRAY_HPP
#define ARRAY_HPP

#include "Type.hpp"
#include <memory>
#include <string>

class Array : public Type {
public:
    std::shared_ptr<Type> of;
    int size = 1;

    Array(int sz, const std::shared_ptr<Type>& p);

    std::string toString();
};

#endif
