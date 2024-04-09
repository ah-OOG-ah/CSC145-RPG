#pragma once

#include <string>
#include <cstdint>
#include "item.h"
#include "Status.h"

class Equipment : public Item
{
    protected:
    int64_t durability;
    public:
    Equipment();
    Equipment(std::string itemName, int64_t durab, int64_t price);
    int64_t GetDurab();
    void SetDurab(int64_t);
    void ChangeAmount(int64_t) override; //Makes it so it amount can not change besides one and zero
    std::string GetAmntText() override; //Vestigal
};

class Weapon : public Equipment
{
    protected:
    int64_t dmgMultiplier;

    public:
    Weapon(std::string itemName, int64_t durab, int64_t dmg, int64_t price);
    int64_t GetDamage();
    void SetDamage(int64_t dmg);
};

class Armor : public Equipment
{
    protected:
    //Defense stats work like those with the player
    int64_t percDef; 
    int64_t staticDef; 

    public:
    Armor(std::string itemName, int64_t durab, int64_t pDef, int64_t sDef, int64_t price);
    int64_t GetPercDef();
    int64_t GetStaticDef();
    void SetPercDef(int64_t);
    void SetStaticDef(int64_t);
};

class SpeicalArmor : public Armor
{
    protected:
    int64_t dmgMultiplier; //Increases damage dealt when worn
    //Status placeholder

    public:
    SpeicalArmor(std::string itemName, int64_t durab, int64_t pDef, int64_t sDef, int64_t dmg, int64_t price);
    int64_t GetDamage();
    void SetDamage(int64_t);

    //Status effect placeholders
};