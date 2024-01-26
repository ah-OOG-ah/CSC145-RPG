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

int64_t Entity::getHp() { return hp; }

int64_t Entity::getX() { return x; }

int64_t Entity::getY() { return y; }

int64_t Entity::getAttk() { return attk; }

int64_t Entity::getStaticDef() { return staticDef; }

int64_t Entity::getPercDef() { return percDef; }

int64_t Entity::getSpd() { return spd; }