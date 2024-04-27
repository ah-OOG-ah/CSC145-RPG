#include <string>
#include <iostream>
#include "game.h"
#include <utility>
#include <memory>
#include "RegularItems.h"


RegularItem::RegularItem(std::string itemName, int64_t price, std::string desc, int64_t amnt)
        : Item(std::move(itemName), price, amnt, std::move(desc)) {}

std::string RegularItem::GetAmntText() {
    return "x";
}

std::unique_ptr<Item> RegularItem::copy() {
    return std::make_unique<RegularItem>(*this);
}


AttackItem::AttackItem(std::string itemName, int64_t dmg, int64_t price, std::string desc, bool spread, int64_t amnt, const std::shared_ptr<Status>& effect, int64_t chance)
    : RegularItem(std::move(itemName), price, std::move(desc)), damage(dmg), status(std::make_shared<Status>(effect)), effectChance(chance), spreadDamage(spread) {
    type = ATTACK;
}

void AttackItem::SetDamage(int64_t dmg) { damage = dmg; }
void AttackItem::SetStatus(std::shared_ptr<Status> effect) { status = std::move(effect); }
void AttackItem::SetChance(int64_t chance) { effectChance = chance; }
void AttackItem::SetSpread(bool spread) { spreadDamage = spread; }

int64_t AttackItem::GetDamage() const { return damage; }
std::shared_ptr<Status> AttackItem::GetStatus() { return status; }
int64_t AttackItem::GetChance() const { return effectChance; }
bool AttackItem::canSpread() const { return spreadDamage; }

void AttackItem::display() {

    std::cout << entries[0] << std::endl;
    std::cout << "Price: " << this->GetPrice() << std::endl;
    std::cout << "Damage: " << this->GetDamage() << std::endl;
    if (this->status != nullptr) {
        std::cout << "Causes: " << this->GetStatus()->GetName() << std::endl;
    }
    std::cout << (spreadDamage ? "Multi-Target" : "Single-Target") << std::endl;
    std::cout << entries[1] << std::endl;
    std::cout << "Enter any key to exit " << std::endl;
    std::string choice;
    std::getline(std::cin, choice);
}

void AttackItem::Use(std::shared_ptr<Entity> user, std::vector<std::shared_ptr<Entity>> opponents) {
    if (this->amount <= 0) return;

    if (this->spreadDamage) {
        std::cout << user->getName() << " used " << this->GetName() << std::endl;
        for (auto target : opponents) {

            target->changeHP(-1 * this->GetDamage());
            std::cout << target->getName() << " took " << this->GetDamage() << " damage " << std::endl;
            if (this->status != nullptr) {

                int64_t chance = randUint() % 10;
                if (chance <= this->effectChance) {
                    Status* ailment = new Status(this->status);
                    //target->setStatus(ailment);
                    std::cout << target->getName() << " was afflicted by " << this->status->GetName() << std::endl;
                }
            }
        }
        this->amount -1;
    } else {

        opponents[0]->changeHP(-1 * this->GetDamage());
        std::cout << user->getName() << " used " << this->GetName() << std::endl;
        std::cout << opponents[0]->getName() << " took " << this->GetDamage() << " damage " << std::endl;
        if (this->status != nullptr) {
            int64_t chance = randUint() % 10;
            if(chance <= this->effectChance) {
                Status* ailment = new Status(this->status);
                //opponents[0]->setStatus(ailment);
                std::cout << opponents[0]->getName() << " was afflicted by " << this->status->GetName() << std::endl;
            }
        }
        this->amount -1;
    }
}

std::unique_ptr<Item> AttackItem::copy() {
    auto ret = std::make_unique<AttackItem>(name, damage, price, description, amount, spreadDamage);
    ret->status = status;
    ret->effectChance = effectChance;
    return ret;
}


HealItem::HealItem(std::string itemName, int64_t hp, int64_t price, std::string desc, int64_t amnt, const std::shared_ptr<Status>& effect)
    : RegularItem(std::move(itemName), price, std::move(desc), amnt), hpAmnt(hp), healedStatus(std::make_shared<Status>(effect)) {
    type = HEAL;
}
HealItem::HealItem(const HealItem* ht) : HealItem(ht->name, ht->hpAmnt, ht->price, ht->description, ht->amount, ht->healedStatus) { }

void HealItem::SetHpAmnt(int64_t hp) { hpAmnt = hp; }
void HealItem::SetHealedStatus(std::shared_ptr<Status> status) { healedStatus = status; }

int64_t HealItem::GetHpAmnt() const { return hpAmnt; }
std::shared_ptr<Status> HealItem::GetHealedStatus() const { return healedStatus; }

void HealItem::display() {
    std::cout << entries[0] << std::endl;
    std::cout << "Price: " << this->GetPrice() << std::endl;
    std::cout << "Heals: " << this->GetHpAmnt() << std::endl;
    if (this->healedStatus != nullptr) {
        std::cout << "Cures: " << this->GetHealedStatus()->GetName() << std::endl;
    }

    std::cout << "Amount: " << this->GetAmount() << this->GetAmntText() << std::endl;
    std::cout << entries[1] << std::endl;
    std::cout << "Enter EXIT to exit or HEAL to heal with this item" << std::endl;
    std::string choice;
    while (choice != "EXIT") {
        std::getline(std::cin, choice);
        if (choice == "HEAL") {
            this->Use(getPlayer(), { });
            if (this->GetAmount() <= 0) {
                return;
            }
        } else if(choice != "EXIT") {
            std::cout << "Invalid input. Please input again. " << std::endl;
        }
    }
}

void HealItem::Use(std::shared_ptr<Entity> user, std::vector<std::shared_ptr<Entity>> opponents) {
    if (this->amount <= 0) return;

    int64_t healedAmnt = this->hpAmnt;
    if ((healedAmnt + user->getCurrentHp()) > user->getMaxHp()) {
        healedAmnt = user->getMaxHp() - user->getCurrentHp();
    }

    user->changeHP(healedAmnt);
    this->amount -1;
    std::cout << user->getName() << " used " << this->GetName() << std::endl;
    if(hpAmnt != 0) {
        std::cout << user->getName() << " HP was restored by " << healedAmnt << "HP" << std::endl;
    }

    if(this->healedStatus != nullptr) {
        /*if(this->healedStatus->GetName() == user->getStatus()->GetName()) {
            user->setStatus(nullptr);
            std::cout << user->getName() << " was cured of " << this->healedStatus->GetName() << std::endl;
        }*/
    }
}

std::unique_ptr<Item> HealItem::copy() {
    return std::make_unique<HealItem>(this);
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

void StatusItem::display() {
    std::cout << entries[0] << std::endl;
    std::cout << "Price: " << this->GetPrice() << std::endl;
    std::cout << "Boosts: " << this->GetStat() << " by " << this->GetBoost() << " Points" << std::endl;
    if (this->status != nullptr) {
        std::cout <<"Causes: " << this->status << std::endl;
    }
    std::cout << "Amount: " << this->GetAmount() << this->GetAmntText() << std::endl;
    std::cout << entries[1] << std::endl;
    std::cout << "Enter EXIT to exit or USE to use this item" << std::endl;
    std::string choice;
    while (choice != "EXIT") {
        std::getline(std::cin, choice);
        if (choice == "USE") {
            this->Use(getPlayer(), { });
            if (this->GetAmount() <= 0) {
                return;
            }
        } else if (choice != "EXIT") {
            std::cout << "Invalid input. Please input again. " << std::endl;
        }
    }
}

void StatusItem::Use(std::shared_ptr<Entity> user, std::vector<std::shared_ptr<Entity>> opponents) {
    if (this->amount <= 0) return;

    if (this->stat == attack) {
        user->changeAttack(this->boost);
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

std::unique_ptr<Item> StatusItem::copy() {
    return std::make_unique<StatusItem>(*this);
}
