#include "Status.h"

#include <cstdint>

Status::Status(std::string n, int64_t turns, int64_t damage, int64_t chance)
{
    name = n;
    turnAmnt = turns;
    damageAmnt = damage;
    effectChance = chance;
}

std::string Status::GetName() { return name; }

int64_t Status::GetTurn() { return turnAmnt; }

int64_t Status::GetDamage() { return damageAmnt; }

int64_t Status::GetChance() { return effectChance; }