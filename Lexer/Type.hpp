#ifndef TYPE_HPP
#define TYPE_HPP

#include "Word.hpp"
#include <memory>

class Type : public Word {
public:
    int width = 0;

    Type(const std::string& s, int tag, int w);

    static const std::shared_ptr<Type> Int;
    static const std::shared_ptr<Type> Float;
    static const std::shared_ptr<Type> Char;
    static const std::shared_ptr<Type> Bool;

    static bool numeric(const std::shared_ptr<Type>& p);
    static std::shared_ptr<Type> max(const std::shared_ptr<Type>& p1, const std::shared_ptr<Type>& p2);
};

bool operator==(const Type& lhs, const Type& rhs);

#endif
