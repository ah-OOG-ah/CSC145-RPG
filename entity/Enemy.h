#pragma once

#include "EquippedEntity.h"
#include <vector>
#include "itemtiers.h"
#include "EnumAI.h"


class Enemy : public EquippedEntity {
  protected:
    std::function<Inventory(void)> invFactory;
    std::function<std::shared_ptr<Weapon>(void)> weaponFactory;
    std::function<ArmorSet(void)> armorFactory;
    std::array<std::string, 5> enemySprite;
    std::vector<std::shared_ptr<Item>> extraLoot;
    EnumAI ai;

  public:
    Enemy(const std::string& name, double hp, double attk, double percDef, double staticDef, int64_t spd, std::array<std::string, 5> sprite = {
            "     ", "     ", "     ", "     ", "     "}, std::vector<std::shared_ptr<Item>> extraLoot = {}, std::function<Inventory(void)> invFactory = [](){ return Inventory(); }, std::function<std::shared_ptr<Weapon>(void)> weaponFactory = [](){ return IDefs::nothing; }, std::function<ArmorSet(void)> armorFactory = [](){ return ITiers::noArmor; }, EnumAI ai = IDIOT);

    // Enemy is a special class - if you just instantiate it, you won't get a weapon, armor, or inventory. These get filled in on copies.
    Enemy(const Enemy&);

    [[nodiscard]] std::array<std::string, 5> getSprite() const;
    [[nodiscard]] std::vector<std::shared_ptr<Item>> getExtraLoot() const;
    [[nodiscard]] EnumAI getAI() const;
    std::vector<std::shared_ptr<Item>> dropLoot();
};
