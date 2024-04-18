#pragma once

#include <string>
#include <cstdint>
#include "item.h"
#include "Status.h"

class RegularItem : public Item {
  public:
    RegularItem(std::string itemName, int64_t price, int64_t amnt);
    RegularItem(std::string itemName, int64_t price);
    //Constructors with descriptions
    RegularItem(std::string itemName, int64_t price, int64_t amnt, std::string desc);
    RegularItem(std::string itemName, int64_t price, std::string desc);
    RegularItem(RegularItem* r);

    std::string GetAmntText() override;
};

class AttackItem : public RegularItem {
  protected:
    int64_t damage;
    Status* status = nullptr;
    int64_t effectChance = 0;

  public:
    AttackItem(std::string itemName, int64_t dmg, int64_t price, Status* effect, int64_t chance);
    AttackItem(std::string itemName, int64_t dmg, int64_t price, int64_t amnt);
    AttackItem(std::string itemName, int64_t dmg, int64_t price);
    //Constructors with descriptions
    AttackItem(std::string itemName, int64_t dmg, int64_t price, Status* effect, int64_t chance, std::string desc);
    AttackItem(std::string itemName, int64_t dmg, int64_t price, int64_t amnt, std::string desc);
    AttackItem(std::string itemName, int64_t dmg, int64_t price, std::string desc);
    AttackItem(AttackItem* at);

    void SetDamage(int64_t dmg);
    void SetStatus(Status* effect);
    void SetChance(int64_t chance);

    [[nodiscard]] int64_t GetDamage() const;
    Status* GetStatus();
    [[nodiscard]] int64_t GetChance() const;
    void display() override;
    void Use(Entity* user, Entity* opponent) override;
};

class HealItem : public RegularItem
{
    protected:
    int64_t hpAmnt;
    Status* healedStatus = nullptr;
    //void dispatch(int64_t i) override;

    public:
    HealItem(std::string itemName, int64_t hp, int64_t price);
    HealItem(std::string itemName, int64_t hp, int64_t price, int64_t amnt);
    //Constructors with descriptions
    HealItem(std::string itemName, int64_t hp, int64_t price, std::string desc);
    HealItem(std::string itemName, int64_t hp, int64_t price, int64_t amnt, std::string desc);
    HealItem(HealItem* ht);
    void SetHpAmnt(int64_t hp);
    void SetHealedStatus(Status* status);

    [[nodiscard]] int64_t GetHpAmnt() const;
    Status* GetHealedStatus();
  
    void display() override;

    void Use(Entity* user, Entity* opponent) override;
};

class NonConsumAttackItem : public AttackItem {
  public:
    //stackable is set to false
    NonConsumAttackItem(std::string itemName, int64_t dmg, int64_t price, Status* effect, int64_t chance);
    NonConsumAttackItem(std::string itemName, int64_t dmg, int64_t price);
    //Constructors with descriptions
    NonConsumAttackItem(std::string itemName, int64_t dmg, int64_t price, Status* effect, int64_t chance, std::string desc);
    NonConsumAttackItem(std::string itemName, int64_t dmg, int64_t price, std::string desc);
    NonConsumAttackItem(NonConsumAttackItem* ncat);
    std::string GetAmntText() override;
};