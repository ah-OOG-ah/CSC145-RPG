#include "EquippedEntity.h"

#include <utility>
#include "Status.h"


EquippedEntity::EquippedEntity(std::string name, double hp, double attk, double percDef, double staticDef, int64_t spd, const Inventory& inv)
    : Entity(std::move(name), hp, attk, percDef, staticDef, spd), inventory(inv), armor(ITiers::noArmor) { }

void EquippedEntity::takeDamage(double amnt) {
    amnt -= staticDef + armor.defenseStatic();
    if (amnt < 0) return;

    amnt *= this->percDef * armor.defenseMult();
    this->hp -= amnt;
}

double EquippedEntity::getAttack() const {
    return attack * armor.offenseMult() * currentWeapon->GetDamage();
}
