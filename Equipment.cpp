#include <string>
#include "Equipment.h"

Equipment(std::string itemName, int64_t durab, int64_t price) : 

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