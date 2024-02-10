#pragma once

#include "Entity.h"
#include "attack.h"
#include <cstdint>

class Player : public Entity {

  public:
    int64_t x;
    int64_t y;
    Attack attack;

    Player(int64_t hp);
    Player(int64_t hp, int64_t x, int64_t y);
};
