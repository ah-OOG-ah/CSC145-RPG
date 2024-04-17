#include "Enemy.h"
#include "Equipment.h"
#include "game.h"
#include <cstdint>

Enemy(std::string name, int64_t hp, int64_t attk, int64_t percDef, int64_t staticDef, int64_t spd, std::vector<RegularItem*> invenSlots, std::vector<Weapon*> weaponSlots, std::vector<Armor*> armorSlots);
 : Enemy(name, hp, attk, percDef, staticDef, spd, invenSlots, weaponSlots, armorSlots, "") {}

Enemy(std::string name, int64_t hp, int64_t attk, int64_t percDef, int64_t staticDef, int64_t spd, std::vector<RegularItem*> invenSlots, std::vector<Weapon*> weaponSlots, std::vector<Armor*> armorSlots, std::string sprite);
 : Entity(name, hp, attk, percDef, staticDef, spd)
{
    this->enemySprite = sprite;

}