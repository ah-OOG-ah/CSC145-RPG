#include <string>
#include <utility>
#include "Equipment.h"
#include <iostream>
#include "game.h"


Equipment::Equipment(std::string itemName, int64_t durab, int64_t price) : Item(std::move(itemName), price, "FIXME") {
    this->durability = durab;
    this->stackable = false;
    this->equipable = true;
}
//Constructor with description
Equipment::Equipment(std::string itemName, int64_t durab, int64_t price, std::string desc) : Item(std::move(itemName), price, std::move(desc)) {
    this->durability = durab;
    this->stackable = false;
    this->equipable = true;
}
Equipment::Equipment(Equipment* e) : Item(e)
{
    this->durability = e->GetDurab();
    this->stackable = false;
    this->equipable = true;
}

int64_t Equipment::GetDurab() const { return durability; }
void Equipment::ChangeDurab(int64_t durab) { durability += durab; }

std::string Equipment::GetAmntText() {
    return "";
}

std::unique_ptr<Item> Equipment::copy() {
    return std::make_unique<Equipment>(this);
}

Weapon::Weapon(std::string itemName, int64_t durab, double dmg, int64_t price) : Equipment(std::move(itemName), durab, price) {
    dmgMultiplier = dmg;
    type = "WEAPON";
}
//Constructor with description
Weapon::Weapon(std::string itemName, int64_t durab, double dmg, int64_t price, std::string desc) : Equipment(std::move(itemName), durab, price, std::move(desc)) {
    dmgMultiplier = dmg;
    type = "WEAPON";
}

Weapon::Weapon(Weapon* w) : Equipment(w)
{
    this->dmgMultiplier = w->GetDamage();
    type = "WEAPON";
}

double Weapon::GetDamage() const { return dmgMultiplier; };

void Weapon::SetDamage(double dmg) { dmgMultiplier = dmg; };

void Weapon::Use(Entity* user, std::vector<Entity*> opponents) {

    /*
    Weapon* oldWeapon = user->currentWeapon;
    user->currentWeapon = this;
    if(oldWeapon != nullptr)
    {
        std::cout << oldWeapon->GetName() << " was unequipped "  << std::endl;
    }
    std::cout << user->getName() << " equipped " << this->GetName() << std::endl;
    user->Inven.RemoveItem(this);
    user->Inven.AddItem(oldWeapon);*/
}

void Weapon::display() {
    std::cout << entries[0] << std::endl;
    std::cout << "WEAPON" << std::endl;
    std::cout << "Price: " << this->GetPrice() << std::endl;
    std::cout << "Strength: " << this->GetDamage() << std::endl;
    std::cout << "Durability: " << this->GetDurab() << std::endl;
    if(getPlayer()->currentWeapon.get() == this) {
        std::cout<< "EQUIPPED" << std::endl;
    } else {
        std::cout << "EQUIPPABLE" << std::endl;
    }
    std::cout << entries[1] << std::endl;
    std::cout << "Enter EXIT to exit or EQUIP to equip this item" << std::endl;
    std::string choice;
    while (choice != "EXIT") {
        std::getline(std::cin, choice);
        if (choice == "EQUIP") {
            this->Use(getPlayer().get(), std::vector<Entity*>{nullptr});
            if (this->GetAmount() <= 0) {
                return;
            }
        } else if (choice != "EXIT") {
            std::cout << "Invalid input. Please input again. " << std::endl;
        }
    }
}

std::unique_ptr<Item> Weapon::copy() {
    return std::make_unique<Weapon>(this);
}

Armor::Armor(std::string itemName, int64_t durab, double pDef, int64_t sDef, int64_t price, ArmorType mold) : Armor(std::move(itemName), durab, pDef, sDef, 1.0 , price, mold) {
    percDef = pDef;
    staticDef = sDef;
    cast = mold;
    type = "ARMOR";
}
Armor::Armor(std::string itemName, int64_t durab, double pDef, int64_t sDef, double dmg, int64_t price, ArmorType mold) : Equipment(std::move(itemName), durab, price) {
    percDef = pDef;
    staticDef = sDef;
    dmgMultiplier = dmg;
    cast = mold;
    type = "ARMOR";
}
//Constructor with description
Armor::Armor(std::string itemName, int64_t durab, double pDef, int64_t sDef, int64_t price, ArmorType mold, std::string desc) : Armor(std::move(itemName), durab, pDef, sDef, 1.0 , price, mold, std::move(desc)) {
    percDef = pDef;
    staticDef = sDef;
    cast = mold;
    type = "ARMOR";
}
Armor::Armor(std::string itemName, int64_t durab, double pDef, int64_t sDef, double dmg, int64_t price, ArmorType mold, std::string desc) : Equipment(std::move(itemName), durab, price, std::move(desc)) {
    percDef = pDef;
    staticDef = sDef;
    dmgMultiplier = dmg;
    cast = mold;
    type = "ARMOR";
}
Armor::Armor(Armor* a) : Equipment(a)
{
    this->percDef = a->GetPercDef();
    this->staticDef = a->GetStaticDef();
    this->dmgMultiplier = a->GetDmgMult();
    this->cast = a->GetArmorType();
    type = "ARMOR";
}

double Armor::GetPercDef() const { return percDef; }
int64_t Armor::GetStaticDef() const { return staticDef; }
double Armor::GetDmgMult() const { return dmgMultiplier; }
ArmorType Armor::GetArmorType() const { return cast; }
void Armor::SetPercDef(double def) { percDef = def; }
void Armor::SetStaticDef(int64_t def) { staticDef = def; }
void Armor::SetDmgMult(double dmg) { dmgMultiplier = dmg; }
void Armor::SetArmorType(ArmorType mold) { cast = mold; }

void Armor::Use(Entity* user, std::vector<Entity*> opponents) {
    /*
    Armor* oldArmor = nullptr;
    if(this->cast == Helmet)
    {
        oldArmor = user->armorArray[0];
        user->armorArray[0] = this;
    }
    else if(this->cast == Chestplate)
    {
        oldArmor = user->armorArray[1];
        user->armorArray[1] = this;
    }
    else if(this->cast == Leggings)
    {
        oldArmor = user->armorArray[2];
        user->armorArray[2] = this;
    }
    else if(this->cast == Boots)
    {
        oldArmor = user->armorArray[3];
        user->armorArray[3] = this;
    }
    if(oldArmor != nullptr)
    {
        std::cout << oldArmor->GetName() << " was unequipped "  << std::endl;
    }
    std::cout << user->getName() << " equipped " << this->GetName() << std::endl;
    user->Inven.RemoveItem(this);
    user->Inven.AddItem(oldArmor);*/
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
    for(int i = 0; i < 4; ++i) {
        auto it = getPlayer()->armor.get(i).get();
        if(it == this) {
            std::cout<< "EQUIPPED" << std::endl;
        } /*else if (it == getPlayer()->armor.get(3)) {
            std::cout << "EQUIPABLE" << std::endl;
        }*/
    }
    std::cout << entries[1] << std::endl;
    std::cout << "Enter EXIT to exit or EQUIP to equip this item" << std::endl;
    std::string choice;
    while (choice != "EXIT") {
        std::getline(std::cin, choice);
        if (choice == "EQUIP") {
            this->Use(getPlayer().get(), std::vector<Entity*>{nullptr});
            if(this->GetAmount() <= 0) {
                return;
            }
        } else if (choice != "EXIT") {
            std::cout << "Invalid input. Please input again. " << std::endl;
        }
    }
}

std::unique_ptr<Item> Armor::copy() {
    return std::make_unique<Armor>(this);
}
