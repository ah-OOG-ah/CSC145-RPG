#pragma once

#include <string>
#include <cstdint>
#include "item.h"
#include "Status.h"

class RegularItem : public Item
{
    public:
    RegularItem(std::string itemName, int64_t amnt, int64_t price);
    RegularItem(std::string itemName, int64_t amnt);
    RegularItem(std::string itemName);
    std::string GetAmntText() override;
};

class AttackItem : public RegularItem
{
    protected:
    int64_t damage;
    Status* status = nullptr;
    int64_t effctChance = 0;

    public:
    AttackItem(std::string itemName, int64_t amnt, int64_t dmg, int64_t price, Status* effect, int64_t chance);
    AttackItem(std::string itemName, int64_t amnt, int64_t dmg, int64_t price);
    AttackItem(std::string itemName, int64_t amnt, int64_t dmg);
    AttackItem(std::string itemName, int64_t dmg);
    void SetDamage(int64_t dmg);
    void SetStatus(Status* effect);
    void SetChance(int64_t chance);

    int64_t GetDamage();
    Status* GetStatus();
    int64_t GetChance();
};

class HealItem : public RegularItem
{
    protected:
    int64_t hpAmnt;
    Status* healedStatus = nullptr;

    public:
    HealItem(std::string itemName, int64_t amnt, int64_t hp, int64_t price, Status* status);
    HealItem(std::string itemName, int64_t amnt, int64_t hp, Status* status);
    HealItem(std::string itemName, int64_t amnt, int64_t hp, int64_t price);
    HealItem(std::string itemName, int64_t amnt, int64_t hp);
    HealItem(std::string itemName, int64_t hp);

    void SetHpAmnt(int64_t hp);
    void SetHealedStatus(Status* status);

    int64_t GetHpAmnt();
    Status* GetHealedStatus();
};

class NonConsumAttackItem : public AttackItem
{
    public:
    NonConsumAttackItem(std::string itemName, int64_t dmg, Status* effect, int64_t chance);
    NonConsumAttackItem(std::string itemName, int64_t dmg);
    virtual void ChangeAmount(int64_t addAmnt) override; 
    std::string GetAmntText() override;
};