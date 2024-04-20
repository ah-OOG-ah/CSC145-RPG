#include "Enemy.h"
#include "Equipment.h"
#include "game.h"
#include <cstdint>
#include <iostream>

Enemy::Enemy(std::string name, int64_t hp, int64_t attk, int64_t percDef, int64_t staticDef, int64_t spd, std::vector<AttackItem> attkSlots, std::vector<HealItem> healSlots, std::vector<StatusItem> statusSlots, std::vector<Weapon*> weaponSlots, std::vector<Armor*> armorSlots)
 : Enemy(name, hp, attk, percDef, staticDef, spd, attkSlots, healSlots, statusSlots, weaponSlots, armorSlots, "") {}

Enemy::Enemy(std::string name, int64_t hp, int64_t attk, int64_t percDef, int64_t staticDef, int64_t spd, std::vector<AttackItem> attkSlots, std::vector<HealItem> healSlots, std::vector<StatusItem> statusSlots, std::vector<Weapon*> weaponSlots, std::vector<Armor*> armorSlots, std::string sprite)
 : Entity(name, hp, attk, percDef, staticDef, spd)
{
    this->enemySprite = sprite;
    //Choosing items for inven
    double amntOfAttk = getRand() % 4;
    if(!attkSlots.empty())
    {
        for(int i = 0; i < amntOfAttk; i++)
        {
            this->Inven.AddItem(&(attkSlots[getRand() % attkSlots.size()]));
        }
    }
    if(!healSlots.empty())
    {
        double amntOfHeal = (getRand() % 5) * (1.0/amntOfAttk);
        for(int i = 0; i < amntOfHeal; i++)
        {
            this->Inven.AddItem(&(healSlots[getRand() % healSlots.size()]));
        }
    }
    if(!statusSlots.empty())
    {
        double amntOfStatus = getRand() % 3;
        for(int i = 0; i < amntOfStatus; i++)
        {
            this->Inven.AddItem(&(statusSlots[getRand() % statusSlots.size()]));
        }
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

void Enemy::dropLoot(Entity* player)
{
    std::vector<Item*> lootVector;
    for(int i = 0; i < this->Inven.GetUsedElements(); i++)
    {
        lootVector.insert(lootVector.begin(), this->Inven.GetItem(i));
    }
    if(!lootVector.empty())
    {
        for(Item* loot : this->extraLoot)
        {
            lootVector.insert(lootVector.begin(), loot);
        }
    }
    for(Item* armor : this->armorArray)
    {
        lootVector.insert(lootVector.begin(), armor);
    }
    lootVector.insert(lootVector.begin(), this->currentWeapon);
    int64_t amntOfLoot = getRand() % 4; //Gives loot 1 to 4
    std::vector<Item*> droppedLoot;
    std::cout<< this->name << " dropped ";
    for(int j = 0; j < amntOfLoot; j++)
    {
        int64_t pos = getRand() % lootVector.size();
        if(lootVector[pos] == nullptr)
        {
            continue;
        }
        std::cout << " a(n) " << lootVector[pos]->GetName() << std::endl;
        droppedLoot.insert(droppedLoot.begin(), lootVector[pos]);
    }
    std::cout << "Collect " << this->name <<"'s loot\? Y/N " << std::endl;
    std::string choice;
    std::getline(std::cin, choice);
    if(choice == "Y" || choice == "y" || choice == "yes" || choice == "YES" || choice == "Yes")
    {
        for(Item* gains : droppedLoot)
        {
            player->Inven.AddItem(gains);
        }
    }
    else
    {
        std::cout << "Loot was discarded" << std::endl;
    }
}