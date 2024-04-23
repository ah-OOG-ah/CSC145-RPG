#pragma once

#include "EquippedEntity.h"
#include <vector>
#include "itemtiers.h"


class Enemy : public EquippedEntity {
  protected:
    std::function<void(Enemy*, EquippedEntity*)> behaviorFunction;
    std::string enemySprite;
    std::vector<Item*> extraLoot;

  public:
    Enemy(std::string name, int64_t hp, int64_t attk, double percDef, int64_t staticDef, int64_t spd, Inventory inv, const std::shared_ptr<Weapon>& weapon, ArmorSet armor, std::function<void(Enemy*, EquippedEntity*)> behavior );
    Enemy(std::string name, int64_t hp, int64_t attk, double percDef, int64_t staticDef, int64_t spd, Inventory inv, const std::shared_ptr<Weapon>& weapon, ArmorSet armor, std::string sprite, std::function<void(Enemy*, EquippedEntity*)> behavior);
    explicit Enemy(Enemy* en);
    [[nodiscard]] std::string getSprite() const;
    [[nodiscard]] std::vector<Item*> getExtraLoot();
    [[nodiscard]] std::string toString() const override;
    std::vector<std::shared_ptr<Item>> dropLoot();
};
