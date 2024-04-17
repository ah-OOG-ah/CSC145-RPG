#pragma once

#include "Entity.h"
#include <vector>
#include "itemtiers.h"

class Enemy : public Entity {
  protected:
  std::string enemySprite;
  public:
    Enemy(std::string name, int64_t hp, int64_t attk, int64_t percDef, int64_t staticDef, int64_t spd, std::vector<RegularItem*> invenSlots, std::vector<Weapon*> weaponSlots, std::vector<Armor*> armorSlots);
    Enemy(std::string name, int64_t hp, int64_t attk, int64_t percDef, int64_t staticDef, int64_t spd, std::vector<RegularItem*> invenSlots, std::vector<Weapon*> weaponSlots, std::vector<Armor*> armorSlots, std::string sprite);
    [[nodiscard]] std::string getSprite() const;
    [[nodiscard]] std::string toString() const override;
};
