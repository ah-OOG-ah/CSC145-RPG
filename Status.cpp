#include "Status.h"

#include <cstdint>
#include <utility>

Status::Status(std::string n, int64_t turns, std::function<void(Entity*, Status*)> func, bool good) : good(good) {
    name = std::move(n);
    maxTurns = turns;
    this->statusFunction = std::move(func);
}

Status::Status(const std::shared_ptr<Status>& st)
    : statusFunction(st->statusFunction), name(st->name), remainingTurns(st->remainingTurns), maxTurns(st->maxTurns) { }

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

bool Status::isGood() {
    return good;
}
