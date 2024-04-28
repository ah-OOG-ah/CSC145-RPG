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
Equipment::Equipment(Equipment* e) : Item(e), durability(e->durability) { }

int64_t Equipment::GetDurab() const { return durability; }
void Equipment::ChangeDurab(int64_t durab) { durability += durab; }

std::string Equipment::GetAmntText() const {
    return "";
}

std::unique_ptr<Item> Equipment::copy() {
    return std::make_unique<Equipment>(this);
}

Weapon::Weapon(std::string itemName, int64_t durab, double dmg, int64_t price) : Equipment(std::move(itemName), durab, price) {
    dmgMultiplier = dmg;
    type = WEAPON;
}
//Constructor with description
Weapon::Weapon(std::string itemName, int64_t durab, double dmg, int64_t price, std::string desc) : Equipment(std::move(itemName), durab, price, std::move(desc)) {
    dmgMultiplier = dmg;
    type = WEAPON;
}

Weapon::Weapon(Weapon* w) : Equipment(w)
{
    this->dmgMultiplier = w->GetDamage();
    type = WEAPON;
}

double Weapon::GetDamage() const { return dmgMultiplier; }

void Weapon::SetDamage(double dmg) { dmgMultiplier = dmg; }

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
            this->use(getPlayer(), {}, <#initializer#>);
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


//Constructor with description
Armor::Armor(std::string itemName, int64_t durab, double pDef, double sDef, int64_t price, ArmorType mold, std::string desc, double dmg)
    : Equipment(std::move(itemName), durab, price, std::move(desc)) {
    percDef = pDef;
    staticDef = sDef;
    dmgMultiplier = dmg;
    cast = mold;
    type = ARMOR;
}
Armor::Armor(Armor* a) : Equipment(a), percDef(a->percDef), staticDef(a->staticDef), dmgMultiplier(a->dmgMultiplier), cast(a->cast) { }

double Armor::GetPercDef() const { return percDef; }
double Armor::GetStaticDef() const { return staticDef; }
double Armor::GetDmgMult() const { return dmgMultiplier; }
ArmorType Armor::GetArmorType() const { return cast; }
void Armor::SetPercDef(double def) { percDef = def; }
void Armor::SetStaticDef(double val) { staticDef = val; }
void Armor::SetDmgMult(double dmg) { dmgMultiplier = dmg; }
void Armor::SetArmorType(ArmorType mold) { cast = mold; }

void Armor::display() {
    std::cout << entries[0] << std::endl;
    switch (cast) {
        case Helmet: std::cout << "HELMET" << std::endl;
            break;
        case Chestplate: std::cout << "CHESTPLATE" << std::endl;
            break;
        case Leggings: std::cout << "LEGGINGS" << std::endl;
            break;
        case Boots: std::cout << "BOOTS" << std::endl;
            break;
    }
    std::cout << "Price: " << this->GetPrice() << std::endl;
    std::cout << "Percentage Defense: " << this->GetPercDef() << std::endl;
    std::cout << "Static Defense: " << this->GetStaticDef() << std::endl;
    std::cout << "Durability: " << this->GetDurab() << std::endl;
    for (int i = 0; i < 4; ++i) {
        auto it = getPlayer()->armor.get(i).get();
        if (it == this) {
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
            this->use(getPlayer(), {}, <#initializer#>);
            if (this->GetAmount() <= 0) {
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
