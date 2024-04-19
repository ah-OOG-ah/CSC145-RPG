#include "Status.h"

#include <cstdint>

Status::Status(std::string n, int64_t turns, std::function<void(Entity*, Status*)> func)
{
    name = n;
    turnAmnt = turns;
    this->statusFunction = func;
}

std::string Status::GetName() { return name; }

int64_t Status::GetTurn() { return turnAmnt; }

void Status::ReduceTurn() { this->turnAmnt -=1; }

void Status::effect(Entity* victim)
{
    this->statusFunction(victim, this);
}