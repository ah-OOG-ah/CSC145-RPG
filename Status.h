#pragma once

#include <cstdint>
#include <string>

class Status
{
    protected:
    std::string name;
    int64_t turnAmnt;
    int64_t damageAmnt;
    int64_t effectChance;

    public:
    Status(std::string n, int64_t turns, int64_t damage, int64_t chance);
    std::string GetName();
    int64_t GetTurn();
    int64_t GetDamage();
    int64_t GetChance();
};