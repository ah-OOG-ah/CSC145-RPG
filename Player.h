#pragma once

#include "Entity.h"
#include <cstdint>

class Player : public Entity {

  public:
    int64_t x;
    int64_t y;

    Player(int64_t hp) : Entity(hp) {}
    Player(int64_t hp, int64_t x, int64_t y) : Entity(hp), x(x), y(y) {}
};
