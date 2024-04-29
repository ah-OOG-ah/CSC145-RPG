#pragma once

#include "Entity.h"
#include <utility>
#include "Equipment.h"
#include "Inventory.h"
#include "ArmorSet.h"
#include "ItemDefs.h"
#include "itemtiers.h"


class EquippedEntity : public Entity {

  public:
    EquippedEntity(std::string name, double hp, double attk, double percDef, double staticDef, int64_t spd, const Inventory& inv = Inventory());

    Inventory inventory;
    std::shared_ptr<Weapon> currentWeapon = IDefs::nothing; //The weapon is set to a "nothing" weapon
    ArmorSet armor;

    void takeDamage(double amnt) override;

    [[nodiscard]] double getAttack() const override;
};