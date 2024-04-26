#include "EquippedEntity.h"

#include <utility>
#include "Status.h"


EquippedEntity::EquippedEntity(std::string name, int64_t hp, int64_t attk, double percDef, int64_t staticDef, int64_t spd, const Inventory& inv)
    : Entity(std::move(name), hp, attk, percDef, staticDef, spd), Inven(inv), armor(ITiers::noArmor) { }
EquippedEntity::EquippedEntity(Entity *e) : Entity(e) {}

void EquippedEntity::takeDamage(double amnt) {
    amnt -= this->staticDef;
    amnt *= this->percDef;
    for (int i = 0; i < 4; i++) {
        amnt -= this->armor.get(i)->GetStaticDef();
        amnt *= this->armor.get(i)->GetPercDef();
    }
    this->hp -= amnt;
}

void EquippedEntity::attackEntity(const std::shared_ptr<Entity>& enemy) {
    enemy->takeDamage(this->attack * this->currentWeapon->GetDamage());
}

double EquippedEntity::getAttack() const {
    return attack * armor.offenseMult() * currentWeapon->GetDamage();
}
