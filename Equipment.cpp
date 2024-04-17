#include <string>
#include <utility>
#include "Equipment.h"
#include <iostream>
#include "game.h"

Equipment::Equipment(std::string itemName, int64_t durab, int64_t price) : Item(std::move(itemName), price, "FIXME") {
    durability = durab;
    stackable = false;
    equipable = true;
}
//Constructor with description
Equipment::Equipment(std::string itemName, int64_t durab, int64_t price, std::string desc) : Item(std::move(itemName), price, std::move(desc)) {
    durability = durab;
    stackable = false;
    equipable = true;
}

int64_t Equipment::GetDurab() const { return durability; }
void Equipment::ChangeDurab(int64_t durab) { durability += durab; }

std::string Equipment::GetAmntText() {
    return "";
}

Weapon::Weapon(std::string itemName, int64_t durab, int64_t dmg, int64_t price) : Equipment(std::move(itemName), durab, price) {
    dmgMultiplier = dmg;
}
//Constructor with description
Weapon::Weapon(std::string itemName, int64_t durab, int64_t dmg, int64_t price, std::string desc) : Equipment(std::move(itemName), durab, price, std::move(desc)) {
    dmgMultiplier = dmg;
}

int64_t Weapon::GetDamage() const { return dmgMultiplier; };

void Weapon::SetDamage(int64_t dmg) { dmgMultiplier = dmg; };

void Weapon::Use(Entity* user, Entity* opponent)
{
    user->currentWeapon = this;
    user->Inven.RemoveItem(this);
}

void Weapon::display()
{
    std::cout << entries[0] << std::endl;
    std::cout << "WEAPON" << std::endl;
    std::cout << "Price: " << this->GetPrice() << std::endl;
    std::cout << "Strength: " << this->GetDamage() << std::endl;
    std::cout << "Durability: " << this->GetDurab() << std::endl;
    if(getPlayer()->currentWeapon == this)
    {
        std::cout<< "EQUIPPED" << std::endl;
    }
    else
    {
        std::cout << "EQUIPABLE" << std::endl;
    }
    std::cout << entries[1] << std::endl;
    std::cout << "Enter EXIT to exit or EQUIP to equip this item" << std::endl;
    std::string choice;
    while(choice != "EXIT")
    {
        std::getline(std::cin, choice);
        if(choice == "EQUIP") 
        {
            this->Use(getPlayer().get(), nullptr);
            if(this->GetAmount() <= 0)
            {
                return;
            }
        }
        else if(choice != "EXIT")
        {
            std::cout << "Invalid input. Please input again. " << std::endl;
        }
    }
    return;
}

Armor::Armor(std::string itemName, int64_t durab, int64_t pDef, int64_t sDef, int64_t price, ArmorType mold) : Armor(std::move(itemName), durab, pDef, sDef, 1 , price, mold) {
    percDef = pDef;
    staticDef = sDef;
}
Armor::Armor(std::string itemName, int64_t durab, int64_t pDef, int64_t sDef, int64_t dmg, int64_t price, ArmorType mold) : Equipment(std::move(itemName), durab, price) {
    percDef = pDef;
    staticDef = sDef;
    dmgMultiplier = dmg;
    cast = mold;
}
//Constructor with description
Armor::Armor(std::string itemName, int64_t durab, int64_t pDef, int64_t sDef, int64_t price, ArmorType mold, std::string desc) : Armor(std::move(itemName), durab, pDef, sDef, 1 , price, mold, std::move(desc)) {
    percDef = pDef;
    staticDef = sDef;
}
Armor::Armor(std::string itemName, int64_t durab, int64_t pDef, int64_t sDef, int64_t dmg, int64_t price, ArmorType mold, std::string desc) : Equipment(std::move(itemName), durab, price, std::move(desc)) {
    percDef = pDef;
    staticDef = sDef;
    dmgMultiplier = dmg;
    cast = mold;
}

int64_t Armor::GetPercDef() const { return percDef; }
int64_t Armor::GetStaticDef() const { return staticDef; }
int64_t Armor::GetDmgMult() const { return dmgMultiplier; }
void Armor::SetPercDef(int64_t def) { percDef = def; }
void Armor::SetStaticDef(int64_t def) { staticDef = def; }
void Armor::SetDmgMult(int64_t dmg) { dmgMultiplier = dmg; }

void Armor::Use(Entity* user, Entity* opponent)
{
    if(this->cast == Helmet)
    {
        user->armorArray[0] = this;
    }
    else if(this->cast == Chestplate)
    {
        user->armorArray[1] = this;
    }
    else if(this->cast == Leggings)
    {
        user->armorArray[2] = this;
    }
    else if(this->cast == Boots)
    {
        user->armorArray[3] = this;
    }
    user->Inven.RemoveItem(this);
}

void Armor::display()
{
    std::cout << entries[0] << std::endl;
    if(this->cast == Helmet)
    {
        std::cout<< "HELMET" << std::endl;
    }
    else if(this->cast == Chestplate)
    {
        std::cout<< "CHESTPLATE" << std::endl;
    }
    else if(this->cast == Leggings)
    {
        std::cout<< "LEGGINGS" << std::endl;
    }
    else if(this->cast == Boots)
    {
        std::cout<< "BOOTS" << std::endl;
    }
    std::cout << "Price: " << this->GetPrice() << std::endl;
    std::cout << "Percentage Defense: " << this->GetPercDef() << std::endl;
    std::cout << "Static Defense: " << this->GetStaticDef() << std::endl;
    std::cout << "Durability: " << this->GetDurab() << std::endl;
    for( Armor* it : getPlayer()->armorArray)
    {
        if(it == this)
        {
            std::cout<< "EQUIPPED" << std::endl;
        }
        else if(it == getPlayer()->armorArray[getPlayer()->armorArray.size() - 1])
        {
            std::cout << "EQUIPABLE" << std::endl;
        }
    }
    std::cout << entries[1] << std::endl;
    std::cout << "Enter EXIT to exit or EQUIP to equip this item" << std::endl;
    std::string choice;
    while(choice != "EXIT")
    {
        std::getline(std::cin, choice);
        if(choice == "EQUIP") 
        {
            this->Use(getPlayer().get(), nullptr);
            if(this->GetAmount() <= 0)
            {
                return;
            }
        }
        else if(choice != "EXIT")
        {
            std::cout << "Invalid input. Please input again. " << std::endl;
        }
    }
    return;
}