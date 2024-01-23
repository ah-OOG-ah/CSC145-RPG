#pragma once

#include <cstdint>

class Entity {

  protected:
    int64_t hp;
    int64_t x;
    int64_t y;

  public:
    Entity(int64_t hp);
    Entity(int64_t hp, int64_t x, int64_t y);

    int64_t getHp();
    int64_t getX();
    int64_t getY();
};
