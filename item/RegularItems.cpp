#include <string>
#include <iostream>
#include "game.h"
#include <utility>
#include <memory>
#include "RegularItems.h"


RegularItem::RegularItem(std::string itemName, int64_t price, std::string desc, int64_t amnt)
        : Item(std::move(itemName), price, amnt, std::move(desc)) {}

std::string RegularItem::GetAmntText() const {
    return " x ";
}


AttackItem::AttackItem(std::string itemName, int64_t dmg, int64_t price, std::string desc, bool spread, int64_t amnt, const std::shared_ptr<Status>& effect, int64_t chance)
    : RegularItem(std::move(itemName), price, std::move(desc)), damage(dmg), status(std::make_shared<Status>(effect)), effectChance(chance), spreadDamage(spread) {
    type = ATTACK;
}

void AttackItem::SetDamage(int64_t dmg) { damage = dmg; }
void AttackItem::SetStatus(std::shared_ptr<Status> effect) { status = std::move(effect); }
void AttackItem::SetChance(int64_t chance) { effectChance = chance; }
void AttackItem::SetSpread(bool spread) { spreadDamage = spread; }

double AttackItem::GetDamage() const { return damage; }
std::shared_ptr<Status> AttackItem::GetStatus() { return status; }
int64_t AttackItem::GetChance() const { return effectChance; }
bool AttackItem::canSpread() const { return spreadDamage; }

void AttackItem::use(const std::shared_ptr<Entity>& user, const std::vector<std::shared_ptr<Entity>>& allies, const std::vector<std::shared_ptr<Entity>>& opponents) {
    if (this->amount <= 0) return;

    for (const auto& e : opponents) {
        double before = e->getCurrentHp();
        e->takeDamage(damage);
        std::cout << user->getName() << " used " << name << " on " << e->getName() << " dealing " << before - e->getCurrentHp() << " damage." << std::endl;
        if (!spreadDamage) break;
    }
}

std::unique_ptr<Item> AttackItem::copy(int64_t amount) const {
    auto ret = std::make_unique<AttackItem>(*this);
    if (amount != 0)
        ret->amount = amount;
    return ret;
}


HealItem::HealItem(std::string itemName, double hp, int64_t price, std::string desc, int64_t amnt, bool splash)
    : RegularItem(std::move(itemName), price, std::move(desc), amnt), hpAmnt(hp), splash(splash) {
    type = HEAL;
}

double HealItem::getHpAmnt() const { return hpAmnt; }

void HealItem::SetHpAmnt(double hp) { hpAmnt = hp; }

void HealItem::use(const std::shared_ptr<Entity>& user, const std::vector<std::shared_ptr<Entity>>& allies, const std::vector<std::shared_ptr<Entity>>& opponents) {
    if (amount <= 0) return;

    --amount;

    if (splash) {
        std::cout << user->getName() << " used " << this->GetName() << " on all allies!" << std::endl;
        for (const auto& e : allies) {
            auto actualHeal = e->changeHP(hpAmnt);
            if (hpAmnt != 0) {
                std::cout << e->getName() << " was restored by " << actualHeal << " HP" << std::endl;
            }
        }
        return;
    }

    auto actualHeal = user->changeHP(hpAmnt);
    std::cout << user->getName() << " used " << this->GetName() << std::endl;
    if (hpAmnt != 0) {
        std::cout << user->getName() << " was restored by " << actualHeal << " HP" << std::endl;
    }
}

std::unique_ptr<Item> HealItem::copy(int64_t amount) const {
    auto ret = std::make_unique<HealItem>(*this);
    if (amount != 0)
        ret->amount = amount;
    return ret;
}


StatusItem::StatusItem(std::string itemName, int64_t price, int64_t boost, statBoost stat, std::string desc, int64_t chance, const std::shared_ptr<Status>& effect, int64_t amnt)
    : RegularItem(std::move(itemName), price, std::move(desc), amnt), boost(boost), stat(stat), status(std::make_shared<Status>(effect)) {
    type = STATUS;
}

void StatusItem::SetBoost(int64_t val) { boost = val; }
void StatusItem::SetStat(statBoost val) { stat = val; }
void StatusItem::SetStatus(std::shared_ptr<Status> effect) { status = std::move(effect); }
void StatusItem::SetChance(int64_t chance) { effectChance = chance; }

int64_t StatusItem::GetBoost() const { return this->boost; }
statBoost StatusItem::GetStat() const { return this->stat; }
std::shared_ptr<Status> StatusItem::GetStatus() { return status; }
int64_t StatusItem::GetChance() const { return this->effectChance; }

void StatusItem::use(const std::shared_ptr<Entity>& user, const std::vector<std::shared_ptr<Entity>>& allies, const std::vector<std::shared_ptr<Entity>>& opponents) {
    if (amount <= 0) return;

    --amount;

    if (stat == attack) {
        user->changeAttack(boost);
        std::cout << user->getName() << " used " << this->name << std::endl;
        std::cout << user->getName() <<"'s Attack was boosted " << this->boost << " points!" << std::endl;
    }
    if (this->stat == percdef) {
        user->changePercDef(this->boost);
        std::cout << user->getName() << " used " << this->name << std::endl;
        std::cout << user->getName() <<"'s PercDef was boosted " << this->boost << " points!" << std::endl;
    }
    if (this->stat == staticdef) {
        user->changeStaticDef(this->boost);
        std::cout << user->getName() << " used " << this->name << std::endl;
        std::cout << user->getName() <<"'s StaticDef was boosted " << this->boost << " points!" << std::endl;
    }
    if (this->stat == speed) {
        user->changeSpd(this->boost);
        std::cout << user->getName() << " used " << this->name << std::endl;
        std::cout << user->getName() <<"'s Speed was boosted " << this->boost << " points!" << std::endl;
    }
    if (this->status != nullptr) {
        int64_t chance = randUint() % 10;
        if (chance <= this->effectChance) {
            Status* ailment = new Status(this->status);
            //user->setStatus(ailment);
            std::cout << user->getName() << " was afflicted by " << this->status->GetName() << std::endl;
        }
    }
    this->amount -1;
}

std::unique_ptr<Item> StatusItem::copy(int64_t amount) const {
    auto ret = std::make_unique<StatusItem>(*this);
    if (amount != 0)
        ret->amount = amount;
    return ret;
}
