#include <cstdint>
#include <string>
#include "Equipment.h"

Equipment::Equipment(std::string itemName, int64_t amnt) : Item(itemName, amnt) { }

std::string Equipment::GetAmntText()
{
    return durability;
}

