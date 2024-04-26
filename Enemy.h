#pragma once

#include "EquippedEntity.h"
#include <vector>
#include "itemtiers.h"


class Enemy : public EquippedEntity {
  protected:
    std::function<void(Enemy*, EquippedEntity*)> behaviorFunction;
    std::function<Inventory(void)> invFactory;
    std::function<std::shared_ptr<Weapon>(void)> weaponFactory;
    std::function<std::shared_ptr<Weapon>(void)> armorFactory;
    std::function<std::vector<std::shared_ptr<Item>>(void)> lootFactory;
    std::array<std::string, 5> enemySprite;
    std::vector<std::shared_ptr<Item>> extraLoot;

  public:
    Enemy(const std::string& name, double hp, double attk, double percDef, double staticDef, int64_t spd, std::array<std::string, 5> sprite = {
            "     ", "     ", "     ", "     ", "     "}, std::vector<std::shared_ptr<Item>> extraLoot = {}, const std::function<void(Enemy*, EquippedEntity*)>& behavior = [](
            Enemy *, EquippedEntity *) {});

    // , const Inventory& inv = {}, const std::shared_ptr<Weapon>& weapon = IDefs::nothing, const ArmorSet& armor = ITiers::noArmor

    [[nodiscard]] std::array<std::string, 5> getSprite() const;
    [[nodiscard]] std::vector<std::shared_ptr<Item>> getExtraLoot() const;
    std::vector<std::shared_ptr<Item>> dropLoot();
};
