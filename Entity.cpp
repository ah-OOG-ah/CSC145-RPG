#include "Entity.h"
#include <cstdint>
#include <string>
#include <utility>
#include <memory>

Entity::Entity(int64_t hp) {
    this->maxHp = hp;
    this->hp = this->maxHp;
}
Entity::Entity(std::string name, int64_t hp, int64_t attk, double percDef, int64_t staticDef, int64_t spd){
    this->name = std::move(name);
    this->maxHp = hp;
    this->hp = this->maxHp;
    this->attk = attk;
    this->percDef = percDef;
    this->staticDef = staticDef;
    this->spd = spd;
}
Entity::Entity(Entity* e) {
    this->name = e->getName();
    this->maxHp = e->getMaxHp();
    this->hp = this->maxHp;
    this->attk = e->getAttk();
    this->percDef = e->getPercDef();
    this->staticDef = e->getStaticDef();
    this->spd = e->getSpd();
}

std::string Entity::getName() const { return name; }

int64_t Entity::getMaxHp() const { return maxHp; }

int64_t Entity::getCurrentHp() const { return hp; }

double Entity::getAttk() const { return attk; }

int64_t Entity::getStaticDef() const { return staticDef; }

double Entity::getPercDef() const { return percDef; }

int64_t Entity::getSpd() const { return spd; }

int64_t Entity::getMp() const { return mp; }

bool Entity::getFleeing() const { return this->isFleeing; }

bool Entity::getCanAct() const { return this->canAct; }

bool Entity::getAlive() const { return this->hp > 0; }

void Entity::setFleeing(bool val) { this->isFleeing = val; }

void Entity::setCanAct(bool val) { this->canAct = val; }

void Entity::changeHP(int64_t hpAmnt) {
    this->hp += hpAmnt; 
}

void Entity::changeAttk(double amnt) {
    this->attk += amnt; 
}

void Entity::changePercDef(double amnt) {
    this->percDef += amnt; 
}

void Entity::changeStaticDef(int64_t amnt) {
    this->staticDef += amnt; 
}

void Entity::changeSpd(int64_t amnt){
    this->spd += amnt; 
}

void Entity::attackEntity(std::shared_ptr<Entity> enemy) {
    enemy->takeDamage(this->getAttk());
}

std::string Entity::toString() const {
    if (this->hp > 0)
        return "{hp: " + std::to_string(this->hp) + ", atk: " + std::to_string(this->attk) + "}";
    return "{DEAD, atk: " + std::to_string(this->attk) + "}";
}

void Entity::takeDamage(double amnt) {
    amnt -= this->staticDef;
    amnt *= this->percDef;
    this->hp -= amnt;
}

bool Entity::operator>(const Entity &other) const {
    return spd > other.spd;
}

void Entity::setSpd(int64_t val) {
    spd = val;
}
