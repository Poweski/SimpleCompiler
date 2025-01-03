#include "Access.hpp"
#include "Tag.hpp"
#include "Type.hpp"

Access::Access(Id* a, Expr* i, Type* p) 
    : Op(new Word("[]", Tag::INDEX), p), array(a), index(i) {}

std::shared_ptr<Expr> Access::gen() {
    return new Access(array, index->reduce(), type);
}

void Access::jumping(int t, int f) {
    emitjumps(reduce()->toString(), t, f);
}

std::string Access::toString() const {
    return array->toString() + " [ " + index->toString() + " ] ";
}
