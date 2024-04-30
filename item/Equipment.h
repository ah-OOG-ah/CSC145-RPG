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
    Equipment(std::string itemName, int64_t durab, int64_t price, std::string desc = "");

    [[nodiscard]] std::unique_ptr<Item> copy(int64_t amount) const override;

    [[nodiscard]] int64_t GetDurab() const;
    void ChangeDurab(int64_t);
    [[nodiscard]] std::string GetAmntText() const override;

    void use(const std::shared_ptr<Entity>& user, const std::vector<std::shared_ptr<Entity>>& allies, const std::vector<std::shared_ptr<Entity>>& opponents) override { };
};

class Weapon : public Equipment {
  protected:
    double dmgMultiplier = 1.0;

  public:
    Weapon(std::string itemName, int64_t durab, double dmg, int64_t price, std::string desc = "");

    [[nodiscard]] std::unique_ptr<Item> copy(int64_t amount) const override;

    [[nodiscard]] double GetDamage() const;

    void SetDamage(double dmg);
};

enum ArmorType { Helmet, Chestplate, Leggings, Boots };

class Armor : public Equipment {
  protected:
    double percDef = 1.00; //Defense stats work like those with the player
    double staticDef;
    double dmgMultiplier = 1.0; //Increases damage dealt when worn
    ArmorType cast;
    //Status placeholder

  public:
    Armor(std::string itemName, int64_t durab, double pDef, double sDef, int64_t price, ArmorType mold, std::string desc, double dmgMult = 1.0);

    [[nodiscard]] std::unique_ptr<Item> copy(int64_t amount) const override;

    [[nodiscard]] double GetPercDef() const;
    [[nodiscard]] double GetStaticDef() const;
    [[nodiscard]] double GetDmgMult() const;
    [[nodiscard]] ArmorType GetArmorType() const;
    void SetPercDef(double);
    void SetStaticDef(double);
    void SetDmgMult(double);
    void SetArmorType(ArmorType);
};