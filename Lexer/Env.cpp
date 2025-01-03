#include "Env.hpp"

Env::Env(std::shared_ptr<Env> n) : prev(n) {}

void Env::put(const Token& w, Id* i) {
    table[w] = i;
}

Id* Env::get(const Token& w) const {
    for (auto e = this; e != nullptr; e = e->prev.get()) {
        auto it = e->table.find(w);
        if (it != e->table.end()) {
            return it->second;
        }
    }
    return nullptr;
}
