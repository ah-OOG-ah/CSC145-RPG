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
        Item* newItem = new Item(invenSlots[getRand() % this->Inven.GetNumElements()]);
        this->Inven.AddItem(newItem);
    }
    int64_t numWeapons = getRand() % 2;
    for(int j = 0; j <= numWeapons; j++)
    {
        Weapon* newWeapon = new Weapon(weaponSlots[getRand() % weaponSlots.size()]);
        if(newWeapon != nullptr)
        {
            newWeapon->Use(this, std::vector<Entity*>{nullptr});
        }
    }
    for(int k = 0; k < 4; k++)
    {
        Armor* newArmor = new Armor(armorSlots[getRand() % armorSlots.size()]); 
        if(newArmor != nullptr)
        {
            newArmor->Use(this, std::vector<Entity*>{nullptr});
        }
    }
}

Enemy::Enemy(std::string name, int64_t hp, int64_t attk, int64_t percDef, int64_t staticDef, int64_t spd, std::vector<RegularItem*> invenSlots, std::vector<Weapon*> weaponSlots, std::vector<Armor*> armorSlots, std::vector<Item*> extraLoot)
 : Enemy(name, hp, attk, percDef, staticDef, spd, invenSlots, weaponSlots, armorSlots, extraLoot, "") {}

Enemy::Enemy(std::string name, int64_t hp, int64_t attk, int64_t percDef, int64_t staticDef, int64_t spd, std::vector<RegularItem*> invenSlots, std::vector<Weapon*> weaponSlots, std::vector<Armor*> armorSlots, std::vector<Item*> extraLoot, std::string sprite)
 : Entity(name, hp, attk, percDef, staticDef, spd)
{
    this->extraLoot = extraLoot;
    this->enemySprite = sprite;
    //Choosing items for inven
    int64_t amntOfItems = 4 + getRand() % 3;
    for(int i = 0; i < amntOfItems; i++)
    {
        Item* newItem = new Item(invenSlots[getRand() % this->Inven.GetNumElements()]);
        this->Inven.AddItem(newItem);
    }
    int64_t numWeapons = getRand() % 2;
    for(int j = 0; j <= numWeapons; j++)
    {
        Weapon* newWeapon = new Weapon(weaponSlots[getRand() % weaponSlots.size()]);
        if(newWeapon != nullptr)
        {
            newWeapon->Use(this, std::vector<Entity*>{nullptr});
        }
    }
    for(int k = 0; k < 4; k++)
    {
        Armor* newArmor = new Armor(armorSlots[getRand() % armorSlots.size()]); 
        if(newArmor != nullptr)
        {
            newArmor->Use(this, std::vector<Entity*>{nullptr});
        }
    }
}

Enemy::Enemy(Enemy* en) : Entity(en) 
{
    this->enemySprite = en->getSprite();
    this->currentWeapon = en->currentWeapon;
    this->armorArray = en->armorArray;
    this->Inven = en->Inven;
    this->extraLoot = en->getExtraLoot();
}

std::string Enemy::getSprite() const
{
    return enemySprite;
}

std::vector<Item*> Enemy::getExtraLoot() { return extraLoot; }

std::string Enemy::toString() const {
    if (this->hp > 0)
        return this->getName() + this->getSprite() + "{hp: " + std::to_string(this->hp) + ", atk: " + std::to_string(this->attk) + "}";
    return this -> getName() + "{DEAD, atk: " + std::to_string(this->attk) + "}";
}