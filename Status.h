#pragma once

#include "Entity.h"
#include <cstdint>
#include <string>
#include <functional>


class Status {
  protected:
    std::function<void(Entity* , Status* )> statusFunction;
    std::string name;
    int64_t remainingTurns;
    int64_t maxTurns;

  public:
    Status(std::string n, int64_t turns, std::function<void(Entity* , Status* )> func);
    explicit Status(const Status*);
    [[nodiscard]] std::string GetName() const;
    [[nodiscard]] int64_t GetRemainingTurns() const;
    [[nodiscard]] int64_t GetMaxTurns() const;
    void ReduceTurn();
    void effect(Entity* victim);
    std::function<void(Entity* , Status* )> getFunc();
};