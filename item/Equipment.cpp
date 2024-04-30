#include <string>
#include <utility>
#include "Equipment.h"
#include <iostream>
#include "game.h"


Equipment::Equipment(std::string itemName, int64_t durab, int64_t price, std::string desc) : Item(std::move(itemName), price, std::move(desc)) {
    this->durability = durab;
    this->stackable = false;
    this->equipable = true;
}

int64_t Equipment::GetDurab() const { return durability; }
void Equipment::ChangeDurab(int64_t durab) { durability += durab; }

std::string Equipment::GetAmntText() const {
    return "";
}

std::unique_ptr<Item> Equipment::copy(int64_t amount) const {
    auto ret = std::make_unique<Equipment>(*this);
    if (amount != 0)
        ret->amount = amount;
    return ret;
}


Weapon::Weapon(std::string itemName, int64_t durab, double dmg, int64_t price, std::string desc) : Equipment(std::move(itemName), durab, price, std::move(desc)) {
    dmgMultiplier = dmg;
    type = WEAPON;
}

double Weapon::GetDamage() const { return dmgMultiplier; }

void Weapon::SetDamage(double dmg) { dmgMultiplier = dmg; }

std::unique_ptr<Item> Weapon::copy(int64_t amount) const {
    auto ret = std::make_unique<Weapon>(*this);
    if (amount != 0)
        ret->amount = amount;
    return ret;
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

double Armor::GetPercDef() const { return percDef; }
double Armor::GetStaticDef() const { return staticDef; }
double Armor::GetDmgMult() const { return dmgMultiplier; }
ArmorType Armor::GetArmorType() const { return cast; }
void Armor::SetPercDef(double def) { percDef = def; }
void Armor::SetStaticDef(double val) { staticDef = val; }
void Armor::SetDmgMult(double dmg) { dmgMultiplier = dmg; }
void Armor::SetArmorType(ArmorType mold) { cast = mold; }

std::unique_ptr<Item> Armor::copy(int64_t amount) const {
    auto ret = std::make_unique<Armor>(*this);
    if (amount != 0)
        ret->amount = amount;
    return ret;
}
