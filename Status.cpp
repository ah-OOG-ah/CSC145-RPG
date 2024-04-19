#include "Status.h"

#include <cstdint>

Status::Status(std::string n, int64_t turns, std::function<void(Entity*, Status*)> func)
{
    name = n;
    maxTurns = turns;
    this->statusFunction = func;
}

Status::Status(Status* st)
{
    this->name = st->GetName();
    this->maxTurns = st->GetMaxTurns();
    this->statusFunction = this->getFunc();
}

std::string Status::GetName() { return name; }

int64_t Status::GetRemainingTurns() { return remainingTurns; }

int64_t Status::GetMaxTurns() { return maxTurns; }

void Status::ReduceTurn() { this->remainingTurns -=1; }

void Status::effect(Entity* victim)
{
    this->statusFunction(victim, this);
}

std::function<void(Entity*, Status*)> Status::getFunc()
{
    this->statusFunction;
}