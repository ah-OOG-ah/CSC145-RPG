#pragma once

#include <string>
#include <cstdint>
#include "Item.h"
#include "Status.h"
#include "statustypes.h"


class RegularItem : public Item {
  public:
    RegularItem(std::string itemName, int64_t price, std::string desc, int64_t amnt = 1);
    explicit RegularItem(const RegularItem *);

    std::unique_ptr<Item> copy() override;

    std::string GetAmntText() override;
};

class AttackItem : public RegularItem {
  protected:
    int64_t damage;
    std::shared_ptr<Status> status = nullptr;
    int64_t effectChance = 0;
    bool spreadDamage = false;

  public:
    AttackItem(std::string itemName, int64_t dmg, int64_t price, std::string desc, bool spread = false, int64_t amnt = 1, const std::shared_ptr<Status>& effect = stypes::none, int64_t chance = 0);

    std::unique_ptr<Item> copy() override;

    void SetDamage(int64_t dmg);
    void SetStatus(std::shared_ptr<Status> effect);
    void SetChance(int64_t chance);
    void SetSpread(bool spread);

    [[nodiscard]] int64_t GetDamage() const;
    std::shared_ptr<Status> GetStatus();
    [[nodiscard]] int64_t GetChance() const;
    [[nodiscard]] bool canSpread() const;
    void display() override;
    void Use(Entity* user , std::vector<Entity* > opponents) override;
};

class HealItem : public RegularItem {
  protected:
    int64_t hpAmnt;
    std::shared_ptr<Status> healedStatus = nullptr;
    //void dispatch(int64_t i) override;

  public:
    HealItem(std::string itemName, int64_t hp, int64_t price, std::string desc, int64_t amnt = 1, const std::shared_ptr<Status>& effect = stypes::none);
    explicit HealItem(const HealItem*);

    std::unique_ptr<Item> copy() override;

    void SetHpAmnt(int64_t hp);
    void SetHealedStatus(std::shared_ptr<Status> status);

    [[nodiscard]] int64_t GetHpAmnt() const;
    [[nodiscard]] std::shared_ptr<Status> GetHealedStatus() const;

    void display() override;

    void Use(Entity* user , std::vector< Entity* > opponents) override;
};

enum statBoost {attack, percdef, staticdef, speed };

class StatusItem : public RegularItem {
  protected:
    int64_t boost;
    statBoost stat;
    std::shared_ptr<Status> status = nullptr;
    int64_t effectChance = 0;

  public:
    StatusItem(std::string itemName, int64_t price, int64_t boost, statBoost stat, std::string desc, int64_t amnt = 1, const std::shared_ptr<Status>& effect = stypes::none, int64_t chance = 0);
    explicit StatusItem(StatusItem* st);

    std::unique_ptr<Item> copy() override;

    void SetBoost(int64_t boost);
    void SetStat(statBoost stat);
    void SetStatus(std::shared_ptr<Status> effect);
    void SetChance(int64_t chance);

    [[nodiscard]] int64_t GetBoost() const;
    [[nodiscard]] statBoost GetStat() const;
    std::shared_ptr<Status> GetStatus();
    [[nodiscard]] int64_t GetChance() const;
    void display() override;
    void Use(Entity* user , std::vector< Entity* > opponents) override;
};