#include "Entity.h"
#include <cstdint>

Entity::Entity(int64_t hp) {
    this->hp = hp;
}

Entity::Entity(int64_t hp, int64_t x, int64_t y) {
    this->hp = hp;
    this->x = x;
    this->y = y;
}
