#pragma once

#include "Entity.h"
#include <utility>
#include "Equipment.h"
#include "inventory.h"


class EquippedEntity : public Entity {
  protected:
    Status* currentStatus = nullptr;

  public:
    EquippedEntity(std::string name, int64_t hp, int64_t attk, double percDef, int64_t staticDef, int64_t spd);
    explicit EquippedEntity(Entity* e);

    Inventory Inven;
    Weapon* currentWeapon = nullptr;
    std::array<Armor*, 4> armorArray = std::array<Armor*, 4>(); //Index of arrays are ordered just like ArmorType enum

    [[nodiscard]] Status* getStatus();
    void setStatus(Status*);
};