#pragma once

#include "Entity.h"
#include <cstdint>
#include <string>

class Status
{
    protected:
    std::function<void(Entity* , Status* )> statusFunction;
    std::string name;
    int64_t remainingTurns;
    int64_t maxTurns;

    public:
    Status(std::string n, int64_t turns, std::function<void(Entity* , Status* )> func);
    Status(Status*);
    std::string GetName();
    int64_t GetRemainingTurns();
    int64_t GetMaxTurns();
    void ReduceTurn();
    void effect(Entity* victim);
    std::function<void(Entity* , Status* )> getFunc();
};