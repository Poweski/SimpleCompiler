#include "Array.hpp"

Array::Array(int sz, const std::shared_ptr<Type>& p)
    : Type("[]", 0, sz * p->width),
      of(p), size(sz) {}

std::string Array::toString() {
    return "[" + std::to_string(size) + "]" + of->toString();
}
