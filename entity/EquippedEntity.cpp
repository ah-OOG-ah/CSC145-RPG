#include "EquippedEntity.h"

#include <utility>
#include "Status.h"


EquippedEntity::EquippedEntity(std::string name, double hp, double attk, double percDef, double staticDef, int64_t spd, const Inventory& inv)
    : Entity(std::move(name), hp, attk, percDef, staticDef, spd), inventory(inv), armor(ITiers::noArmor) { }

void EquippedEntity::takeDamage(double amnt) {
    amnt -= this->staticDef;
    amnt *= this->percDef;
    for (int i = 0; i < 4; i++) {
        amnt -= armor[i]->GetStaticDef();
        amnt *= armor[i]->GetPercDef();
    }
    this->hp -= amnt;
}

void EquippedEntity::attackEntity(const std::shared_ptr<Entity>& enemy) {
    enemy->takeDamage(this->attack * this->currentWeapon->GetDamage());
}

double EquippedEntity::getAttack() const {
    return attack * armor.offenseMult() * currentWeapon->GetDamage();
}
