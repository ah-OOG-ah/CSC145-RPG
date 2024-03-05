#include <cstdint>
#include <string>
#include "Equipment.h"

Equipment::Equipment(std::string itemName, int64_t durab) : Item(itemName, durab) { }
Equipment::Equipment(std::string itemName, int64_t durab, int64_t price) : Item(itemName, durab, price) { }

std::string Equipment::GetAmntText()
{
    return "Durability: ";
}

Weapon::Weapon(std::string itemName, int64_t amnt, int64_t dmg) : Equipment(itemName, amnt)
{
    damage = dmg;
}

Weapon::Weapon(std::string itemName, int64_t amnt, int64_t dmg, int64_t price) : Equipment(itemName, amnt, price)
{
    damage = dmg;
}

int64_t GetDamage();

void SetDamage(int64_t dmg);