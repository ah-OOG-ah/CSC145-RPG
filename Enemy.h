#pragma once

#include "EquippedEntity.h"
#include <vector>
#include "itemtiers.h"


class Enemy : public EquippedEntity {
  protected:
    std::function<void(Enemy*, EquippedEntity*)> behaviorFunction;
    std::string enemySprite;
    std::vector<std::shared_ptr<Item>> extraLoot;

  public:
    Enemy(std::string name, int64_t hp, int64_t attk, double percDef, int64_t staticDef, int64_t spd, Inventory inv = {}, const std::shared_ptr<Weapon>& weapon = nullptr, ArmorSet armor = ITiers::noArmor, std::string sprite = "", std::vector<std::shared_ptr<Item>> extraLoot = {}, std::function<void(Enemy*, EquippedEntity*)> behavior = [](Enemy*, EquippedEntity*){});
    explicit Enemy(Enemy* en);
    explicit Enemy(const std::shared_ptr<Enemy>& en);

    [[nodiscard]] std::string getSprite() const;
    [[nodiscard]] std::vector<std::shared_ptr<Item>> getExtraLoot();
    [[nodiscard]] std::string toString() const override;
    std::vector<std::shared_ptr<Item>> dropLoot();
};
