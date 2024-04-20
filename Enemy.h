#pragma once

#include "Entity.h"
#include <vector>
#include "itemtiers.h"

class Enemy : public Entity {
  protected:
  std::string enemySprite;
  std::vector<Item*> extraLoot;
  public:
    Enemy(std::string name, int64_t hp, int64_t attk, int64_t percDef, int64_t staticDef, int64_t spd, std::vector<AttackItem> attkSlots, std::vector<HealItem> healSlots, std::vector<StatusItem> statusSlots, std::vector<Weapon*> weaponSlots, std::vector<Armor*> armorSlots);
    Enemy(std::string name, int64_t hp, int64_t attk, int64_t percDef, int64_t staticDef, int64_t spd, std::vector<AttackItem> attkSlots, std::vector<HealItem> healSlots, std::vector<StatusItem> statusSlots, std::vector<Weapon*> weaponSlots, std::vector<Armor*> armorSlots, std::string sprite);
    Enemy(std::string name, int64_t hp, int64_t attk, int64_t percDef, int64_t staticDef, int64_t spd, std::vector<AttackItem> attkSlots, std::vector<HealItem> healSlots, std::vector<StatusItem> statusSlots, std::vector<Weapon*> weaponSlots, std::vector<Armor*> armorSlots, std::vector<Item*> extraLoot);
    Enemy(std::string name, int64_t hp, int64_t attk, int64_t percDef, int64_t staticDef, int64_t spd, std::vector<AttackItem> attkSlots, std::vector<HealItem> healSlots, std::vector<StatusItem> statusSlots, std::vector<Weapon*> weaponSlots, std::vector<Armor*> armorSlots, std::vector<Item*> extraLoot, std::string sprite);
    Enemy(Enemy* en);
    [[nodiscard]] std::string getSprite() const;
    [[nodiscard]] std::vector<Item*> getExtraLoot();
    [[nodiscard]] std::string toString() const override;
    void dropLoot(Entity* player);
};
