#include "Entity.h"
#include <cstdint>

Entity::Entity(int64_t hp) {
    this->hp = hp;
}

int64_t Entity::getHp() { return hp; }

int64_t Entity::getAttk() { return attk; }

int64_t Entity::getStaticDef() { return staticDef; }

int64_t Entity::getPercDef() { return percDef; }

int64_t Entity::getSpd() { return spd; }

bool Entity::getFleeing() { return this->isFleeing; }


void Entity::setFleeing(bool val) { this->isFleeing = val; }