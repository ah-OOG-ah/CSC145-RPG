#pragma once

#include <string>
#include <cstdint>
#include "Item.h"
#include "Status.h"


class RegularItem : public Item {
  public:
    RegularItem(std::string itemName, int64_t price, std::string desc, int64_t amnt = 1);
    explicit RegularItem(RegularItem *);

    std::string GetAmntText() override;
};

class AttackItem : public RegularItem {
  protected:
    int64_t damage;
    Status* status = nullptr;
    int64_t effectChance = 0;
    bool spreadDamage = false;

  public:
    AttackItem(std::string itemName, int64_t dmg, int64_t price, std::string desc, int64_t amnt = 1, bool spread = false);
    AttackItem(std::string itemName, int64_t dmg, int64_t price, std::string desc, Status* effect, int64_t chance, bool spread = false);

    void SetDamage(int64_t dmg);
    void SetStatus(Status* effect);
    void SetChance(int64_t chance);
    void SetSpread(bool spread);

    [[nodiscard]] int64_t GetDamage() const;
    Status* GetStatus();
    [[nodiscard]] int64_t GetChance() const;
    [[nodiscard]] bool canSpread() const;
    void display() override;
    void Use(Entity* user , std::vector< Entity* > opponents) override;
};

class HealItem : public RegularItem {
  protected:
    int64_t hpAmnt;
    Status* healedStatus = nullptr;
    //void dispatch(int64_t i) override;

  public:
    HealItem(std::string itemName, int64_t hp, int64_t price, std::string desc, Status* effect);
    HealItem(std::string itemName, int64_t hp, int64_t price, std::string desc, int64_t amnt = 1);
    explicit HealItem(HealItem*);

    void SetHpAmnt(int64_t hp);
    void SetHealedStatus(Status* status);

    [[nodiscard]] int64_t GetHpAmnt() const;
    Status* GetHealedStatus();

    void display() override;

    void Use(Entity* user , std::vector< Entity* > opponents) override;
};

enum statBoost {attack, percdef, staticdef, speed };

class StatusItem : public RegularItem {
  protected:
    int64_t boost;
    statBoost stat;
    Status* status = nullptr;
    int64_t effectChance = 0;

  public:
    StatusItem(std::string itemName, int64_t price, int64_t boost, statBoost stat, std::string desc, int64_t amnt = 1);
    StatusItem(std::string itemName, int64_t price, int64_t boost, statBoost stat, std::string desc, Status* effect, int64_t chance);
    StatusItem(StatusItem* st);

    void SetBoost(int64_t boost);
    void SetStat(statBoost stat);
    void SetStatus(Status* effect);
    void SetChance(int64_t chance);

    [[nodiscard]] int64_t GetBoost() const;
    [[nodiscard]] statBoost GetStat() const;
    Status* GetStatus();
    [[nodiscard]] int64_t GetChance() const;
    void display() override;
    void Use(Entity* user , std::vector< Entity* > opponents) override;
};