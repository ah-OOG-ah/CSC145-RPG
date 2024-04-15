#pragma once

#include <string>
#include <cstdint>
#include "item.h"
#include "Status.h"

class Equipment : public Item {
  protected:
    int64_t durability;
    //stackable is set to false
  public:
    Equipment(std::string itemName, int64_t durab, int64_t price);
    Equipment(std::string itemName, int64_t durab, int64_t price, std::string desc);
    [[nodiscard]] int64_t GetDurab() const;
    void SetDurab(int64_t);
    std::string GetAmntText() override; // Vestigal
};

class Weapon : public Equipment {
  protected:
    int64_t dmgMultiplier;

  public:
    Weapon(std::string itemName, int64_t durab, int64_t dmg, int64_t price);
    Weapon(std::string itemName, int64_t durab, int64_t dmg, int64_t price, std::string desc);
    [[nodiscard]] int64_t GetDamage() const;
    void SetDamage(int64_t dmg);
};

class Armor : public Equipment {
  protected:
    //Defense stats work like those with the player
    int64_t percDef; 
    int64_t staticDef; 

  public:
    Armor(std::string itemName, int64_t durab, int64_t pDef, int64_t sDef, int64_t price);
    Armor(std::string itemName, int64_t durab, int64_t pDef, int64_t sDef, int64_t price, std::string desc);
    [[nodiscard]] int64_t GetPercDef() const;
    [[nodiscard]] int64_t GetStaticDef() const;
    void SetPercDef(int64_t);
    void SetStaticDef(int64_t);
};

class SpecialArmor : public Armor {
  protected:
    int64_t dmgMultiplier; //Increases damage dealt when worn
    //Status placeholder

  public:
    SpecialArmor(std::string itemName, int64_t durab, int64_t pDef, int64_t sDef, int64_t dmg, int64_t price);
    SpecialArmor(std::string itemName, int64_t durab, int64_t pDef, int64_t sDef, int64_t dmg, int64_t price, std::string desc);
    [[nodiscard]] int64_t GetDmgMult() const;
    void SetDmgMult(int64_t);

    //Status effect placeholders
};