#pragma once

#include "Entity.h"
#include "inventory.h"
#include "Equipment.h"
#include <cstdint>

class Player : public Entity {

  public:
    int64_t x;
    int64_t y;
    Inventory playerInven;
    Weapon* currentWeapon;
    Armor* currentArmor;

    Player(int64_t hp);
    Player(int64_t hp, int64_t x, int64_t y);
};
