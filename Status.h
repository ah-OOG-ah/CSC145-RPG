#pragma once

#include "entity/Entity.h"
#include <cstdint>
#include <string>
#include <functional>
#include <memory>


class Status {
  protected:
    std::function<void(Entity* , Status* )> statusFunction;
    std::string name;
    int64_t remainingTurns;
    int64_t maxTurns;
    bool good;
    bool group;

  public:
    Status(std::string n, int64_t turns, std::function<void(Entity* , Status* )> func, bool good);
    explicit Status(const std::shared_ptr<Status>&);

    [[nodiscard]] std::string GetName() const;
    [[nodiscard]] int64_t GetRemainingTurns() const;
    [[nodiscard]] int64_t GetMaxTurns() const;
    [[nodiscard]] bool isGood();
    std::function<void(Entity* , Status* )> getFunc();

    void ReduceTurn();
    void effect(Entity* victim);
};