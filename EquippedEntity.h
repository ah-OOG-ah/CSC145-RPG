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
    EquippedEntity(std::string name, double hp, double attk, double percDef, double staticDef, int64_t spd, const Inventory& inv = {});
    explicit EquippedEntity(Entity* e);

    Inventory Inven;
    std::shared_ptr<Weapon> currentWeapon = IDefs::nothing; // {dynamic_cast<Weapon*>(IDefs::nothing->copy().release())};
    ArmorSet armor; //Index of arrays are ordered just like ArmorType enum

    void takeDamage(double amnt) override;
    void attackEntity(const std::shared_ptr<Entity>& enemy) override;

    double getAttack() const override;
};