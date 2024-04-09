#include <string>
#include "Equipment.h"

Equipment(std::string itemName, int64_t durab, int64_t price) : Item(itemName, price, durab) {}

std::string Equipment::GetAmntText()
{
    return "Durability: ";
}

Weapon::Weapon(std::string itemName, int64_t amnt, int64_t dmg) : Equipment(itemName, amnt)
{
    dmgMultiplier = dmg;
}

Weapon::Weapon(std::string itemName, int64_t amnt, int64_t dmg, int64_t price) : Equipment(itemName, amnt, price)
{
    dmgMultiplier = dmg;
}

int64_t Weapon::GetDamage() { return dmgMultiplier; };

void Weapon::SetDamage(int64_t dmg) { dmgMultiplier = dmg; };

Armor::Armor(std::string itemName, int64_t durab, int64_t pDef, int64_t sDef, int64_t price) : Equipment(itemName, durab, price)
{
    percDef = pDef;
    staticDef = sDef;
}
int64_t Armor::GetPercDef() { return percDef; }
int64_t GetStaticDef() { return staticDef; }
void SetPercDef(int64_t def) { percDef = def; }
void SetStaticDef(int64_t def) { staticDef = def; }