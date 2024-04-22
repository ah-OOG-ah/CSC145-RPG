#pragma once

#include "Entity.h"
#include "Equipment.h"
#include "inventory.h"

class EquippedEntity : public Entity
{
    public:
    explicit EquippedEntity(std::string name, int64_t hp, int64_t attk, double percDef, int64_t staticDef, int64_t spd) : Entity(name, hp, attk, percDef, staticDef, spd) {}
    EquippedEntity(Entity* e) : Entity(e) {}

    Inventory Inven;
    Weapon* currentWeapon;
    std::array<Armor*, 4> armorArray; //Index of arrays are ordered just like ArmorType enum
};