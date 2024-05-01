#pragma once

#include <string>
#include <cstdint>
#include "Item.h"
#include "Status.h"
#include "statustypes.h"
#include "ItemTypes.h"


class RegularItem : public Item {
  public:
    RegularItem(std::string itemName, int64_t price, std::string desc, int64_t amnt = 1);

    std::unique_ptr<Item> copy() override;

    [[nodiscard]] std::string GetAmntText() const override; //Returns "x" for when item amount is displayed
};

class AttackItem : public RegularItem {
  protected:
    double damage; //Damage dealt
    std::shared_ptr<Status> status = nullptr; //Status to inflict on targets
    int64_t effectChance = 0; //Chance to inflict status
    bool spreadDamage = false; //Whether it hits all targets or not

  public:
    AttackItem(std::string itemName, int64_t dmg, int64_t price, std::string desc, bool spread = false, int64_t amnt = 1, const std::shared_ptr<Status>& effect = stypes::none, int64_t chance = 0);

    std::unique_ptr<Item> copy() override;

    void SetDamage(int64_t dmg);
    void SetStatus(std::shared_ptr<Status> effect);
    void SetChance(int64_t chance);
    void SetSpread(bool spread);

    [[nodiscard]] double GetDamage() const;
    std::shared_ptr<Status> GetStatus();
    [[nodiscard]] int64_t GetChance() const;
    [[nodiscard]] bool canSpread() const;
    void display() override; //Displays item menu
    void use(const std::shared_ptr<Entity>& user, const std::vector<std::shared_ptr<Entity>>& allies, const std::vector<std::shared_ptr<Entity>>& opponents) override;
};

class HealItem : public RegularItem {
  protected:
    double hpAmnt; //Amount of hp restored
    std::shared_ptr<Status> healedStatus = nullptr; //Status that it heals
    //void dispatch(int64_t i) override;

  public:
    HealItem(std::string itemName, double hp, int64_t price, std::string desc, int64_t amnt = 1, const std::shared_ptr<Status>& effect = stypes::none);
    explicit HealItem(const HealItem*);

    std::unique_ptr<Item> copy() override;

    void SetHpAmnt(double hp);
    void SetHealedStatus(std::shared_ptr<Status> status);

    [[nodiscard]] double GetHpAmnt() const;
    [[nodiscard]] std::shared_ptr<Status> GetHealedStatus() const;

    void display() override; //Displays item menu

    void use(const std::shared_ptr<Entity>& user, const std::vector<std::shared_ptr<Entity>>& allies, const std::vector<std::shared_ptr<Entity>>& opponents) override;
};

enum statBoost { attack, percdef, staticdef, speed };

class StatusItem : public RegularItem {
  protected:
    int64_t boost; //Amount stat will be boosted by
    statBoost stat; //Stat to boost
    std::shared_ptr<Status> status = nullptr; //Status that it inflicts on user
    int64_t effectChance = 0; //Chance to inflict status

  public:
    StatusItem(std::string itemName, int64_t price, int64_t boost, statBoost stat, std::string desc, int64_t amnt = 1, const std::shared_ptr<Status>& effect = stypes::none, int64_t chance = 0);

    std::unique_ptr<Item> copy() override;

    void SetBoost(int64_t boost);
    void SetStat(statBoost stat);
    void SetStatus(std::shared_ptr<Status> effect);
    void SetChance(int64_t chance);

    [[nodiscard]] int64_t GetBoost() const;
    [[nodiscard]] statBoost GetStat() const;
    std::shared_ptr<Status> GetStatus();
    [[nodiscard]] int64_t GetChance() const; 
    void display() override; //Displays item menu
    void use(const std::shared_ptr<Entity>& user, const std::vector<std::shared_ptr<Entity>>& allies, const std::vector<std::shared_ptr<Entity>>& opponents) override;
};