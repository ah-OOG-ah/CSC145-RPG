#pragma once

#include <string>
#include <cstdint>
#include "item.h"
#include "Status.h"
#include "Entity.h"

class Equipment : public Item {
  protected:
    int64_t durability;
    //stackable is set to false
  public:
    Equipment(std::string itemName, int64_t durab, int64_t price);
    Equipment(std::string itemName, int64_t durab, int64_t price, std::string desc);
    [[nodiscard]] int64_t GetDurab() const;
    void ChangeDurab(int64_t);
    std::string GetAmntText() override;
};

class Weapon : public Equipment {
  protected:
    int64_t dmgMultiplier;

  public:
    Weapon(std::string itemName, int64_t durab, int64_t dmg, int64_t price);
    Weapon(std::string itemName, int64_t durab, int64_t dmg, int64_t price, std::string desc);
    Weapon(Weapon* w);
    [[nodiscard]] int64_t GetDamage() const;
    void SetDamage(int64_t dmg);
    void Use(Entity* user, Entity* opponent) override;
    void display() override;
};

enum ArmorType { Helmet, Chestplate, Leggings, Boots};

class Armor : public Equipment {
  protected:
    int64_t percDef; //Defense stats work like those with the player
    int64_t staticDef; 
    int64_t dmgMultiplier = 1; //Increases damage dealt when worn
    ArmorType cast;
    //Status placeholder

  public:
    Armor(std::string itemName, int64_t durab, int64_t pDef, int64_t sDef, int64_t price, ArmorType mold);
    Armor(std::string itemName, int64_t durab, int64_t pDef, int64_t sDef, int64_t dmg, int64_t price, ArmorType mold);
    //Constructors with Descriptions
    Armor(std::string itemName, int64_t durab, int64_t pDef, int64_t sDef, int64_t price, ArmorType mold, std::string desc);
    Armor(std::string itemName, int64_t durab, int64_t pDef, int64_t sDef, int64_t dmg, int64_t price, ArmorType mold, std::string desc);
    Armor(Armor* a);
    [[nodiscard]] int64_t GetPercDef() const;
    [[nodiscard]] int64_t GetStaticDef() const;
    [[nodiscard]] int64_t GetDmgMult() const;
    void SetPercDef(int64_t);
    void SetStaticDef(int64_t);
    void SetDmgMult(int64_t);
    void Use(Entity* user, Entity* opponent) override;
    void display() override;
};