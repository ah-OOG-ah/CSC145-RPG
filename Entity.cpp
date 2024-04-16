#include "Entity.h"
#include <cstdint>
#include <string>

Entity::Entity(int64_t hp) {
    this->hp = hp;
}

std::string Entity::getName() const { return name; }

int64_t Entity::getHp() const { return hp; }

int64_t Entity::getAttk() const { return attk; }

int64_t Entity::getStaticDef() const { return staticDef; }

int64_t Entity::getPercDef() const { return percDef; }

int64_t Entity::getSpd() const { return spd; }

int64_t Entity::getMp() const { return mp; }

bool Entity::getFleeing() const { return this->isFleeing; }

bool Entity::getAlive() const { return this->hp > 0; }

void Entity::setFleeing(bool val) { this->isFleeing = val; }

void Entity::changeHP(int64_t hpAmnt){
    this->hp += hpAmnt; 
}

void Entity::attackEntity(Entity* enemy) const {
    enemy->hp -= this->getAttk();
}

std::string Entity::toString() const {
    if (this->hp > 0)
        return "{hp: " + std::to_string(this->hp) + ", atk: " + std::to_string(this->attk) + "}";
    return "{DEAD, atk: " + std::to_string(this->attk) + "}";
}
