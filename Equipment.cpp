#include <string>
#include <utility>
#include "Equipment.h"

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
void Equipment::SetDurab(int64_t durab) { durability = durab; }

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

Armor::Armor(std::string itemName, int64_t durab, int64_t pDef, int64_t sDef, int64_t price) : Equipment(std::move(itemName), durab, price) {
    percDef = pDef;
    staticDef = sDef;
}
//Constructor with description
Armor::Armor(std::string itemName, int64_t durab, int64_t pDef, int64_t sDef, int64_t price, std::string desc) : Equipment(std::move(itemName), durab, price, std::move(desc)) {
    percDef = pDef;
    staticDef = sDef;
}

int64_t Armor::GetPercDef() const { return percDef; }
int64_t Armor::GetStaticDef() const { return staticDef; }
void Armor::SetPercDef(int64_t def) { percDef = def; }
void Armor::SetStaticDef(int64_t def) { staticDef = def; }

SpecialArmor::SpecialArmor(std::string itemName, int64_t durab, int64_t pDef, int64_t sDef, int64_t dmg, int64_t price) : Armor(std::move(itemName), durab, pDef, sDef, price) {
    dmgMultiplier = dmg;
}
SpecialArmor::SpecialArmor(std::string itemName, int64_t durab, int64_t pDef, int64_t sDef, int64_t dmg, int64_t price, std::string desc) : Armor(std::move(itemName), durab, pDef, sDef, price, std::move(desc)) {
    dmgMultiplier = dmg;
}

int64_t SpecialArmor::GetDmgMult() const { return dmgMultiplier; }
void SpecialArmor::SetDmgMult(int64_t dmg) { dmgMultiplier = dmg; }