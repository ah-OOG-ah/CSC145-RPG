#pragma once

#include "EquippedEntity.h"
#include <cstdint>

class Player : public EquippedEntity {

  public:
    int64_t x;
    int64_t y;

    Player(int64_t hp);
    Player(int64_t hp, int64_t x, int64_t y);
};
