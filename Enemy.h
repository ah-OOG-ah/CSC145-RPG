#pragma once

#include "EquippedEntity.h"
#include <vector>
#include "itemtiers.h"


class Enemy : public EquippedEntity {
  protected:
    std::function<void(Enemy*, EquippedEntity*)> behaviorFunction;
    std::array<std::string, 5> enemySprite;
    std::vector<std::shared_ptr<Item>> extraLoot;

  public:
    Enemy(const std::string& name, double hp, double attk, double percDef, double staticDef, int64_t spd, const Inventory& inv = {}, const std::shared_ptr<Weapon>& weapon = IDefs::nothing, const ArmorSet& armor = ITiers::noArmor, std::array<std::string, 5> sprite = {
            "     ", "     ", "     ", "     ", "     "}, std::vector<std::shared_ptr<Item>> extraLoot = {}, const std::function<void(Enemy*, EquippedEntity*)>& behavior = [](
            Enemy *, EquippedEntity *) {});
    explicit Enemy(Enemy* en);
    explicit Enemy(const std::shared_ptr<Enemy>& en);

    [[nodiscard]] std::array<std::string, 5> getSprite() const;
    [[nodiscard]] std::vector<std::shared_ptr<Item>> getExtraLoot();
    std::vector<std::shared_ptr<Item>> dropLoot();
};
