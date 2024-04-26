#include "EquippedEntity.h"

#include <utility>
#include "Status.h"


EquippedEntity::EquippedEntity(std::string name, int64_t hp, int64_t attk, double percDef, int64_t staticDef, int64_t spd)
    : Entity(std::move(name), hp, attk, percDef, staticDef, spd) {}
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

void EquippedEntity::attackEntity(std::shared_ptr<Entity> enemy) {
    enemy->takeDamage(this->attk * this->currentWeapon->GetDamage());
}
