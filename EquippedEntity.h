#pragma once

#include "Entity.h"
#include <utility>
#include "Equipment.h"
#include "inventory.h"
#include "ArmorSet.h"
#include "ItemDefs.h"
#include "itemtiers.h"


class EquippedEntity : public Entity {

  public:
    EquippedEntity(std::string name, int64_t hp, int64_t attk, double percDef, int64_t staticDef, int64_t spd);
    explicit EquippedEntity(Entity* e);

    Inventory Inven;
    std::shared_ptr<Weapon> currentWeapon = IDefs::nothing;
    ArmorSet armor = ITiers::noArmor; //Index of arrays are ordered just like ArmorType enum

    void takeDamage(double amnt) override;
    void attackEntity(std::shared_ptr<Entity> enemy) override;
};