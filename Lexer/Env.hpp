#ifndef ENV_HPP
#define ENV_HPP

#include <unordered_map>
#include <memory>
#include "Token.hpp"
#include "Id.hpp"

class Env {
private:
    std::unordered_map<Token, Id*, TokenHash> table;
    std::shared_ptr<Env> prev;

public:
    Env(std::shared_ptr<Env> n = nullptr);

    void put(const Token& w, Id* i);
    Id* get(const Token& w) const;
};

#endif
