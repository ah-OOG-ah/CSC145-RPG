#include "Entity.h"
#include <cstdint>
#include <string>

Entity::Entity(int64_t hp) {
    this->hp = hp;
}

int64_t Entity::getHp() { return hp; }

int64_t Entity::getAttk() { return attk; }

int64_t Entity::getStaticDef() { return staticDef; }

int64_t Entity::getPercDef() { return percDef; }

int64_t Entity::getSpd() { return spd; }

int64_t Entity::getMp() { return mp; }

bool Entity::getFleeing() { return this->isFleeing; }

bool Entity::getAlive() { return this->hp > 0; }

void Entity::setFleeing(bool val) { this->isFleeing = val; }

void Entity::attackEntity(Entity* enemy) {
    enemy->hp -= this->getAttk();
}

std::string Entity::toString() {
    return "{hp: " + std::to_string(this->hp) + ", atk: " + std::to_string(this->attk) + "}";
}
