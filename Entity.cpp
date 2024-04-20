#include "Entity.h"
#include <cstdint>
#include <string>

Entity::Entity(int64_t hp) {
    this->maxHp = hp;
    this->hp = this->maxHp;
}
Entity::Entity(std::string name, int64_t hp, int64_t attk, int64_t percDef, int64_t staticDef, int64_t spd){
    this->name = name;
    this->maxHp = hp;
    this->hp = this->maxHp;
    this->attk = attk;
    this->percDef = percDef;
    this->staticDef = staticDef;
    this->spd = spd;
}
Entity::Entity(Entity* e)
{
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

int64_t Entity::getAttk() const { return attk; }

int64_t Entity::getStaticDef() const { return staticDef; }

int64_t Entity::getPercDef() const { return percDef; }

int64_t Entity::getSpd() const { return spd; }

int64_t Entity::getMp() const { return mp; }

Status* Entity::getStatus() { return this->currentStatus; }

bool Entity::getFleeing() const { return this->isFleeing; }

bool Entity::getCanAct() const { return this->canAct; }

bool Entity::getAlive() const { return this->hp > 0; }

void Entity::setFleeing(bool val) { this->isFleeing = val; }

void Entity::setCanAct(bool val) { this->canAct = val; }

void Entity::changeHP(int64_t hpAmnt){
    this->hp += hpAmnt; 
}

void Entity::changeAttk(int64_t amnt){
    this->attk += amnt; 
}

void Entity::changePercDef(int64_t amnt){
    this->percDef += amnt; 
}

void Entity::changeStaticDef(int64_t amnt){
    this->staticDef += amnt; 
}

void Entity::changeSpd(int64_t amnt){
    this->spd += amnt; 
}

void Entity::setStatus(Status* ailment) { this->currentStatus = ailment; }

void Entity::attackEntity(Entity* enemy) {
    enemy->changeHP(-1 * this->getAttk());
}

std::string Entity::toString() const {
    if (this->hp > 0)
        return "{hp: " + std::to_string(this->hp) + ", atk: " + std::to_string(this->attk) + "}";
    return "{DEAD, atk: " + std::to_string(this->attk) + "}";
}
