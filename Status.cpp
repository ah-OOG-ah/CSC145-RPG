#include "Status.h"

#include <cstdint>
#include <utility>

Status::Status(std::string n, int64_t turns, std::function<void(Entity*, Status*)> func) {
    name = std::move(n);
    maxTurns = turns;
    this->statusFunction = std::move(func);
}

Status::Status(const Status* st) {
    this->name = st->GetName();
    this->maxTurns = st->GetMaxTurns();
    this->statusFunction = this->getFunc();
}

std::string Status::GetName() const { return name; }

int64_t Status::GetRemainingTurns() const { return remainingTurns; }

int64_t Status::GetMaxTurns() const { return maxTurns; }

void Status::ReduceTurn() { this->remainingTurns -=1; }

void Status::effect(Entity* victim) {
    this->statusFunction(victim, this);
}

std::function<void(Entity*, Status*)> Status::getFunc() {
    return statusFunction;
}