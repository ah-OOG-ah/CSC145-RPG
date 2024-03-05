#pragma once

#include <string>
#include <cstdint>
#include "item.h"
#include "Status.h"

class Equipment : public Item
{
    public:
    Equipment(std::string itemName, int64_t durab);
    Equipment(std::string itemName, int64_t durab, int64_t price);
    std::string GetAmntText() override;
};

class Weapon : public Equipment
{
    protected:
    int64_t damage;

    public:
    Weapon(std::string itemName, int64_t amnt, int64_t dmg);
    Weapon(std::string itemName, int64_t durab, int64_t dmg, int64_t price);
    int64_t GetDamage();
    void SetDamage(int64_t dmg);
};