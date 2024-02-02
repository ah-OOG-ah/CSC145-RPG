#pragma once

#include <string>
#include <cstdint>
#include "item.h"
#include "Status.h"

class RegularItem : public Item
{
    protected:
    std::string uses = "x";

    public:
    RegularItem(std::string itemName, int64_t amnt) : Item(itemName, amnt) {}
    std::string GetAmntText() override;
};

class AttackItem : public RegularItem
{
    protected:
    int64_t damage;
    Status* status = nullptr;
    int64_t effctChance;

    public:
    AttackItem(std::string itemName, int64_t amnt, int64_t dmg, Status* effect, int64_t chance) : RegularItem(itemName, amnt)
    {
        damage = dmg;
        status = effect;
        effctChance = chance;
    }
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
    HealItem(std::string itemName, int64_t amnt, int64_t hp, Status* status) : RegularItem(itemName, amnt)
    {
        hpAmnt = hp;
            healedStatus = status;
    }

    void SetHpAmnt(int64_t hp);
    void SetHealedStatus(Status* status);

    int64_t GetHpAmnt();
    Status* GetHealedStatus();
};