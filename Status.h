#pragma once

#include "Entity.h"
#include <cstdint>
#include <string>

class Status
{
    protected:
    std::function<void(Entity*, Status*)> statusFunction;
    std::string name;
    int64_t turnAmnt;

    public:
    Status(std::string n, int64_t turns, std::function<void(Entity*, Status*)> func);
    std::string GetName();
    int64_t GetTurn();
    void ReduceTurn();
    void effect(Entity* victim);
};