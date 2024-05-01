#pragma once

#include "EquippedEntity.h"
#include <vector>
#include "itemtiers.h"
#include "EnumAI.h"


class Enemy : public EquippedEntity {
  protected:
    std::function<Inventory(void)> invFactory; //Assigns inventory items to enemies
    std::function<std::shared_ptr<Weapon>(void)> weaponFactory; //Assigns weapon to enemies
    std::function<ArmorSet(void)> armorFactory; //Assigns the armor to the enemy 
    std::array<std::string, 5> enemySprite;
    std::vector<std::shared_ptr<Item>> extraLoot; //Loot that is not in the inventory. Looting not yet implemented. 
    EnumAI ai; //The enum corresponds to the AI function the enemy uses

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
