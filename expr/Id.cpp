#include "Id.hpp"

Id::Id(Word id, Type p, int b)
    : Expr(id, p),
      offset(b)
{}
