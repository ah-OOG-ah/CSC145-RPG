#include <cstdint>
#include <string>
#include "Equipment.h"

Equipment::Equipment(std::string itemName, int64_t amnt) : Item(itemName, amnt) { }

std::string Equipment::GetAmntText()
{
    return durability;
}

Weapon::Weapon(std::string itemName, int64_t amnt, int64_t dmg) : Equipment(itemName, amnt)
{
    damage = dmg;
}

int64_t GetDamage();

void SetDamage(int64_t dmg);