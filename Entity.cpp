#include "Entity.h"
#include <cstdint>
#include <string>
#include <utility>
#include <memory>

Entity::Entity(double hp) : maxHp(hp), hp(hp) { }
Entity::Entity(std::string name, double hp, double attk, double percDef, double staticDef, int64_t spd)
    : name(std::move(name)), maxHp(hp), hp(hp), percDef(percDef), staticDef(staticDef), spd(spd) { }
Entity::Entity(Entity* e)
    : name(e->name), maxHp(e->maxHp), hp(e->hp), percDef(e->percDef), staticDef(e->staticDef), spd(e->spd) { }

std::string Entity::getName() const { return name; }

double Entity::getMaxHp() const { return maxHp; }
double Entity::getCurrentHp() const { return hp; }
double Entity::getAttack() const { return attack; }
double Entity::getStaticDef() const { return staticDef; }
double Entity::getPercDef() const { return percDef; }
int64_t Entity::getSpd() const { return spd; }
double Entity::getMp() const { return mp; }
bool Entity::getFleeing() const { return isFleeing; }
bool Entity::getCanAct() const { return canAct; }
bool Entity::getAlive() const { return hp > 0; }

void Entity::setFleeing(bool val) { isFleeing = val; }
void Entity::setCanAct(bool val) { canAct = val; }

void Entity::changeHP(double val) { hp += val; }
void Entity::changeAttack(double amnt) { attack += amnt; }
void Entity::changePercDef(double amnt) { percDef += amnt; }
void Entity::changeStaticDef(double amnt) { staticDef += amnt; }
void Entity::changeSpd(int64_t amnt){ spd += amnt; }

void Entity::attackEntity(const std::shared_ptr<Entity>& enemy) { enemy->takeDamage(this->getAttack()); }

std::string Entity::toString() const {

    std::string ret = "HP: xx.xx, ATK: xx.xx";
    if (hp > 0) {
        std::snprintf(ret.data(), 24, "HP: %5.2lf, ATK: %5.2lf", (double) hp, getAttack());
    } else {
        std::snprintf(ret.data(), 24, "HP: DEAD, ATK: %5.2lf", getAttack());
    }
    return ret;
}

void Entity::takeDamage(double amnt) {
    amnt -= this->staticDef;
    amnt *= this->percDef;
    hp -= amnt;
}

bool Entity::operator>(const Entity &other) const {
    return spd > other.spd;
}

void Entity::setSpd(int64_t val) {
    spd = val;
}
