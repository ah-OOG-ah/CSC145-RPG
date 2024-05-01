#include "Entity.h"
#include <cstdint>
#include <string>
#include <utility>
#include <memory>
#include <cmath>

Entity::Entity(double hp) : maxHp(hp), hp(hp) { }
Entity::Entity(std::string name, double hp, double attk, double percDef, double staticDef, int64_t spd)
    : name(std::move(name)), maxHp(hp), hp(hp), attack(attk), percDef(percDef), staticDef(staticDef), spd(spd) { }
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

double Entity::changeHP(double val) { auto delta = hp; hp += val; hp = std::min(hp, maxHp); return hp - delta; }
void Entity::changeAttack(double amnt) { attack += amnt; }
void Entity::changePercDef(double amnt) { percDef += amnt; }
void Entity::changeStaticDef(double amnt) { staticDef += amnt; }
void Entity::changeSpd(int64_t amnt){ spd += amnt; }

void Entity::attackEntity(const std::shared_ptr<Entity>& enemy) { enemy->takeDamage(this->getAttack()); }

std::string Entity::toString() const {

    std::string ret = "HP xx.xx ATK xx.xx DEF xx|xx";
    if (hp > 0) {
        std::snprintf(ret.data(), 29, "HP %5.2lf ATK %5.2lf DEF %2d|%2d", (double) hp, getAttack(), std::min((int) std::round(getStaticDef()), 99), std::min((int) std::round(100.0 * (1.0 - getPercDef())), 99));
    } else {
        std::snprintf(ret.data(), 29, "HP DEAD  ATK %5.2lf DEF %2d|%2d", getAttack(), std::min((int) std::round(getStaticDef()), 99), std::min((int) std::round(100.0 * (1.0 - getPercDef())), 99));
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
