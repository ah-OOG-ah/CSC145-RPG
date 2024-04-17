#include "Enemy.h"
#include "Equipment.h"
#include "game.h"
#include <cstdint>

Enemy::Enemy(std::string name, int64_t hp, int64_t attk, int64_t percDef, int64_t staticDef, int64_t spd, std::vector<RegularItem*> invenSlots, std::vector<Weapon*> weaponSlots, std::vector<Armor*> armorSlots)
 : Enemy(name, hp, attk, percDef, staticDef, spd, invenSlots, weaponSlots, armorSlots, "") {}

Enemy::Enemy(std::string name, int64_t hp, int64_t attk, int64_t percDef, int64_t staticDef, int64_t spd, std::vector<RegularItem*> invenSlots, std::vector<Weapon*> weaponSlots, std::vector<Armor*> armorSlots, std::string sprite)
 : Entity(name, hp, attk, percDef, staticDef, spd)
{
    this->enemySprite = sprite;
    //Choosing items for inven
    int64_t amntOfItems = 4 + getRand() % 3;
    for(int i = 0; i < amntOfItems; i++)
    {
        this->Inven.AddItem(invenSlots[getRand() % this->Inven.GetNumElements()]);
    }
    int64_t numWeapons = getRand() % 2;
    for(int j = 0; j <= numWeapons; j++)
    {
        weaponSlots[getRand() % weaponSlots.size()]->Use(this, nullptr); //Equips armor automatically. If armor already equipped adds old armor to inventory
    }
    for(int k = 0; k < 4; k++)
    {
        armorSlots[getRand() % armorSlots.size()]->Use(this, nullptr); 
    }
}

std::string Enemy::getSprite() const
{
    return enemySprite;
}

std::string Enemy::toString() const {
    if (this->hp > 0)
        return this->getName() + this->getSprite() + "{hp: " + std::to_string(this->hp) + ", atk: " + std::to_string(this->attk) + "}";
    return this -> getName() + "{DEAD, atk: " + std::to_string(this->attk) + "}";
}