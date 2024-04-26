#pragma once

#include <string>
#include <cstdint>
#include "Item.h"
#include "Status.h"


class Equipment : public Item {
  protected:
    int64_t durability;
    //stackable is set to false
  public:
    Equipment(std::string itemName, int64_t durab, int64_t price);
    Equipment(std::string itemName, int64_t durab, int64_t price, std::string desc);
    explicit Equipment(Equipment* e);

    std::unique_ptr<Item> copy() override;

    [[nodiscard]] int64_t GetDurab() const;
    void ChangeDurab(int64_t);
    std::string GetAmntText() override;
};

class Weapon : public Equipment {
  protected:
    double dmgMultiplier = 1.0;

  public:
    Weapon(std::string itemName, int64_t durab, double dmg, int64_t price);
    Weapon(std::string itemName, int64_t durab, double dmg, int64_t price, std::string desc);
    explicit Weapon(Weapon* w);

    std::unique_ptr<Item> copy() override;

    [[nodiscard]] double GetDamage() const;
    void SetDamage(double dmg);
    void Use(Entity*, std::vector<Entity*>) override;
    void display() override;
};

enum ArmorType { Helmet, Chestplate, Leggings, Boots };

class Armor : public Equipment {
  protected:
    double percDef = 1.00; //Defense stats work like those with the player
    int64_t staticDef;
    double dmgMultiplier = 1.0; //Increases damage dealt when worn
    ArmorType cast;
    //Status placeholder

  public:
    Armor(std::string itemName, int64_t durab, double pDef, double sDef, int64_t price, ArmorType mold, std::string desc = "");
    Armor(std::string itemName, int64_t durab, double pDef, double sDef, int64_t price, double dmgMult, ArmorType mold, std::string desc = "");
    explicit Armor(Armor* a);

    std::unique_ptr<Item> copy() override;

    [[nodiscard]] double GetPercDef() const;
    [[nodiscard]] double GetStaticDef() const;
    [[nodiscard]] double GetDmgMult() const;
    [[nodiscard]] ArmorType GetArmorType() const;
    void SetPercDef(double);
    void SetStaticDef(int64_t);
    void SetDmgMult(double);
    void SetArmorType(ArmorType);
    void Use(Entity*, std::vector<Entity* >) override;
    void display() override;
};