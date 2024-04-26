#pragma once

#include "EquippedEntity.h"
#include <cstdint>


class Player : public EquippedEntity {

  public:
    int64_t x;
    int64_t y;

    explicit Player(int64_t hp, int64_t x = 0, int64_t y = 0);
};
