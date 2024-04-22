#include <string>
#include <iostream>
#include "game.h"
#include <utility>
#include <memory>
#include "RegularItems.h"

RegularItem::RegularItem(std::string itemName, int64_t price) : RegularItem(std::move(itemName), price, 1) {}
RegularItem::RegularItem(std::string itemName, int64_t price, int64_t amnt)
    : Item(std::move(itemName), price, amnt, "FIXME") {}
//Constructors with descriptions
RegularItem::RegularItem(std::string itemName, int64_t price, std::string desc) : RegularItem(std::move(itemName), price, 1, std::move(desc)) {}
RegularItem::RegularItem(std::string itemName, int64_t price, int64_t amnt, std::string desc)
    : Item(std::move(itemName), price, amnt, std::move(desc)) {}
RegularItem::RegularItem(RegularItem* r) : Item(r) {}

std::string RegularItem::GetAmntText() {
    return "x";
}

AttackItem::AttackItem(std::string itemName, int64_t dmg, int64_t price, Status* effect, int64_t chance, bool spread) : RegularItem(std::move(itemName), price) {
    damage = dmg;
    Status* ailment = new Status(effect);
    status = ailment;
    effectChance = chance;
    this->spreadDamage = spread;
    type = "ATTACK";
}
AttackItem::AttackItem(std::string itemName, int64_t dmg, int64_t price, int64_t amnt, bool spread) : RegularItem(std::move(itemName), price, amnt) {
    damage = dmg;
    this->spreadDamage = spread;
    type = "ATTACK";
}
AttackItem::AttackItem(std::string itemName, int64_t dmg, int64_t price, bool spread) : RegularItem(std::move(itemName), price) {
    damage = dmg;
    this->spreadDamage = spread;
    type = "ATTACK";
}
//Constructors with descriptions
AttackItem::AttackItem(std::string itemName, int64_t dmg, int64_t price, Status* effect, int64_t chance, bool spread, std::string desc) : RegularItem(std::move(itemName), price, std::move(desc)) {
    damage = dmg;
    Status* ailment = new Status(effect);
    status = effect;
    effectChance = chance;
    this->spreadDamage = spread;
    type = "ATTACK";
}
AttackItem::AttackItem(std::string itemName, int64_t dmg, int64_t price, int64_t amnt, bool spread, std::string desc) : RegularItem(std::move(itemName), price, amnt, std::move(desc)) {
    damage = dmg;
    this->spreadDamage = spread;
    type = "ATTACK";
}
AttackItem::AttackItem(std::string itemName, int64_t dmg, int64_t price, bool spread, std::string desc) : RegularItem(std::move(itemName), price, std::move(desc)) {
    damage = dmg;
    this->spreadDamage = spread;
    type = "ATTACK";
}
AttackItem::AttackItem(AttackItem* at) : RegularItem(at)
{
    this->damage = at->GetDamage();
    Status* ailment = new Status(at->GetStatus());
    this->status = ailment;
    this->effectChance = at->GetChance();
    this->spreadDamage = at->canSpread();
    type = "ATTACK";
}

void AttackItem::SetDamage(int64_t dmg) { damage = dmg; }
void AttackItem::SetStatus(Status* effect) { status = effect; }
void AttackItem::SetChance(int64_t chance) { effectChance = chance; }
void AttackItem::SetSpread(bool spread) { spreadDamage = spread; }

int64_t AttackItem::GetDamage() const { return damage; }
Status* AttackItem::GetStatus() { return status; }
int64_t AttackItem::GetChance() const { return effectChance; }
bool AttackItem::canSpread() const { return spreadDamage; }

void AttackItem::display()
{
    std::cout << entries[0] << std::endl;
    std::cout << "Price: " << this->GetPrice() << std::endl;
    std::cout << "Damage: " << this->GetDamage() << std::endl;
    if(this->status != nullptr)
    {
        std::cout << "Causes: " << this->GetStatus()->GetName() << std::endl;
    }
    if(this->spreadDamage)
    {
        std::cout << "Multi-Target" << std::endl;
    }
    else
    {
        std::cout << "Single-Target" << std::endl;
    }
    std::cout << entries[1] << std::endl;
    std::cout << "Enter any key to exit " << std::endl;
    std::string choice;
    std::getline(std::cin, choice);
    return;
}

void AttackItem::Use(EquippedEntity* user, std::vector<EquippedEntity*> opponents)
{
    if(this->spreadDamage)
    {
        user->Inven.RemoveItem(user->Inven.GetPos(this), 1);
        std::cout << user->getName() << " used " << this->GetName() << std::endl;
        for(Entity* target : opponents)
        {
            target->changeHP(-1 * this->GetDamage());
            std::cout << target->getName() << " took " << this->GetDamage() << " damage " << std::endl;
            if(this->status != nullptr)
            {
                int64_t chance = getRand() % 10;
                if(chance <= this->effectChance) 
                {
                    Status* ailment = new Status(this->status);
                    target->setStatus(ailment);
                    std::cout << target->getName() << " was afflicted by " << this->status->GetName() << std::endl;
                }
            }
        }
        user->Inven.RemoveItem(user->Inven.GetPos(this), 1);
    }
    else
    {
        opponents[0]->changeHP(-1 * this->GetDamage());
        std::cout << user->getName() << " used " << this->GetName() << std::endl;
        std::cout << opponents[0]->getName() << " took " << this->GetDamage() << " damage " << std::endl;
        if(this->status != nullptr)
        {
            int64_t chance = getRand() % 10;
            if(chance <= this->effectChance) 
            {
                Status* ailment = new Status(this->status);
                opponents[0]->setStatus(ailment);
                std::cout << opponents[0]->getName() << " was afflicted by " << this->status->GetName() << std::endl;
            }
        }
        user->Inven.RemoveItem(user->Inven.GetPos(this), 1);
    }
}

HealItem::HealItem(std::string itemName, int64_t hp, int64_t price) : RegularItem(std::move(itemName), price) {
    hpAmnt = hp;
    type = "HEAL";
}
HealItem::HealItem(std::string itemName, int64_t hp, int64_t price, int64_t amnt) : RegularItem(std::move(itemName), price, amnt) {
    hpAmnt = hp;
    type = "HEAL";
}
//Constructors with descriptions
HealItem::HealItem(std::string itemName, int64_t hp, int64_t price, std::string desc) : RegularItem(std::move(itemName), price, std::move(desc)) {
    hpAmnt = hp;
    type = "HEAL";
}
HealItem::HealItem(std::string itemName, int64_t hp, int64_t price, int64_t amnt, std::string desc) : RegularItem(std::move(itemName), price, amnt, std::move(desc)) {
    hpAmnt = hp;
    type = "HEAL";
}
HealItem::HealItem(std::string itemName, int64_t hp, int64_t price, Status* effect, std::string desc) : RegularItem(std::move(itemName), price, std::move(desc)) {
    hpAmnt = hp;
    Status* cure = new Status(effect);
    this->healedStatus = cure;
    type = "HEAL";
}
HealItem::HealItem(HealItem* ht) : RegularItem(ht)
{
    this->hpAmnt = ht->GetHpAmnt();
    Status* cure = new Status(ht->GetHealedStatus());
    this->healedStatus = cure;
    type = "HEAL";
}

void HealItem::SetHpAmnt(int64_t hp) { hpAmnt = hp; }
void HealItem::SetHealedStatus(Status* status) { healedStatus = status; }

int64_t HealItem::GetHpAmnt() const { return hpAmnt; }
Status* HealItem::GetHealedStatus() { return healedStatus; }

void HealItem::display()
{
    std::cout << entries[0] << std::endl;
    std::cout << "Price: " << this->GetPrice() << std::endl;
    std::cout << "Heals: " << this->GetHpAmnt() << std::endl;
    if(this->healedStatus != nullptr)
    {
        std::cout << "Cures: " << this->GetHealedStatus()->GetName() << std::endl;
    }
    std::cout << "Amount: " << this->GetAmount() << this->GetAmntText() << std::endl;
    std::cout << entries[1] << std::endl;
    std::cout << "Enter EXIT to exit or HEAL to heal with this item" << std::endl;
    std::string choice;
    while(choice != "EXIT")
    {
        std::getline(std::cin, choice);
        if(choice == "HEAL") 
        {
            this->Use(getPlayer().get(), std::vector<EquippedEntity*>{nullptr});
            if(this->GetAmount() <= 0)
            {
                return;
            }
        }
        else if(choice != "EXIT")
        {
            std::cout << "Invalid input. Please input again. " << std::endl;
        }
    }
    return;
}

void HealItem::Use(EquippedEntity* user, std::vector<EquippedEntity*> opponents)
{
    int64_t healedAmnt = this->hpAmnt;
    if((healedAmnt + user->getCurrentHp()) > user->getMaxHp())
    {
        healedAmnt = user->getMaxHp() - user->getCurrentHp();
    }
    user->changeHP(healedAmnt);
    user->Inven.RemoveItem(user->Inven.GetPos(this), 1);
    std::cout << user->getName() << " used " << this->GetName() << std::endl;
    if(hpAmnt != 0)
    {
        std::cout << user->getName() << " HP was restored by " << healedAmnt << "HP" << std::endl;
    }
    if(this->healedStatus != nullptr)
    {
        if(this->healedStatus->GetName() == user->getStatus()->GetName()) {
            user->setStatus(nullptr);
            std::cout << user->getName() << " was cured of " << this->healedStatus->GetName() << std::endl;
        }
    }
}

StatusItem::StatusItem(std::string itemName, int64_t boost, statBoost stat, int64_t price, Status* effect, int64_t chance) : StatusItem(itemName, boost, stat, price, effect, chance, "NONE") {}

StatusItem::StatusItem(std::string itemName, int64_t boost, statBoost stat, int64_t price, int64_t amnt) : StatusItem(itemName, boost, stat, price, amnt, "NONE") {}
StatusItem::StatusItem(std::string itemName, int64_t boost, statBoost stat, int64_t price) : StatusItem(itemName, boost, stat, price, "NONE") {}
//Constructors with descriptions
StatusItem::StatusItem(std::string itemName, int64_t boost, statBoost stat, int64_t price, Status* effect, int64_t chance, std::string desc) : RegularItem(itemName, price, desc)
{
    this->boost = boost;
    this->stat = stat;
    Status* cure = effect;
    this->status = cure;
    type = "STATUS";
}
StatusItem::StatusItem(std::string itemName, int64_t boost, statBoost stat, int64_t price, int64_t amnt, std::string desc) : RegularItem(itemName, price, amnt, desc)
{
    this->boost = boost;
    this->stat = stat;
    type = "STATUS";
}
StatusItem::StatusItem(std::string itemName, int64_t boost, statBoost stat, int64_t price, std::string desc) : RegularItem(itemName, price, desc)
{
    this->boost = boost;
    this->stat = stat;
    type = "STATUS";
}
StatusItem::StatusItem(StatusItem* st) : RegularItem(st)
{
    this->boost =st->GetBoost();
    this->stat = st->GetStat();
    Status* cure = new Status(st->GetStatus());
    this->status = cure;
    type = "STATUS";
}

void StatusItem::SetBoost(int64_t boost) { this->boost = boost; }
void StatusItem::SetStat(statBoost stat) { this->stat = stat; }
void StatusItem::SetStatus(Status* effect) { status = effect; }
void StatusItem::SetChance(int64_t chance) { effectChance = chance; }

int64_t StatusItem::GetBoost() const { return this->boost; }
statBoost StatusItem::GetStat() const { return this->stat; }
Status* StatusItem::GetStatus() { return this->status; }
int64_t StatusItem::GetChance() const { return this->effectChance; }

void StatusItem::display()
{
    std::cout << entries[0] << std::endl;
    std::cout << "Price: " << this->GetPrice() << std::endl;
    std::cout << "Boosts: " << this->GetStat() << " by " << this->GetBoost() << " Points" << std::endl;
    if(this->status != nullptr)
    {
        std::cout <<"Causes: " << this->status << std::endl;
    }
    std::cout << "Amount: " << this->GetAmount() << this->GetAmntText() << std::endl;
    std::cout << entries[1] << std::endl;
    std::cout << "Enter EXIT to exit or USE to use this item" << std::endl;
    std::string choice;
    while(choice != "EXIT")
    {
        std::getline(std::cin, choice);
        if(choice == "USE") 
        {
            this->Use(getPlayer().get(), std::vector<EquippedEntity*>{nullptr});
            if(this->GetAmount() <= 0)
            {
                return;
            }
        }
        else if(choice != "EXIT")
        {
            std::cout << "Invalid input. Please input again. " << std::endl;
        }
    }
    return;
}

void StatusItem::Use(EquippedEntity* user, std::vector<EquippedEntity*> opponents)
{
    if(this->stat == attack)
    {
        user->changeAttk(this->boost);
        std::cout << user->getName() << " used " << this->name << std::endl;
        std::cout << user->getName() <<"'s Attack was boosted " << this->boost << " points!" << std::endl;
    }
    if(this->stat == percdef)
    {
        user->changePercDef(this->boost);
        std::cout << user->getName() << " used " << this->name << std::endl;
        std::cout << user->getName() <<"'s PercDef was boosted " << this->boost << " points!" << std::endl;
    }
    if(this->stat == staticdef)
    {
        user->changeStaticDef(this->boost);
        std::cout << user->getName() << " used " << this->name << std::endl;
        std::cout << user->getName() <<"'s StaticDef was boosted " << this->boost << " points!" << std::endl;
    }
    if(this->stat == speed)
    {
        user->changeSpd(this->boost);
        std::cout << user->getName() << " used " << this->name << std::endl;
        std::cout << user->getName() <<"'s Speed was boosted " << this->boost << " points!" << std::endl;
    }
    if(this->status != nullptr)
    {
        int64_t chance = getRand() % 10;
        if(chance <= this->effectChance) 
        {
            Status* ailment = new Status(this->status);
            user->setStatus(ailment);
            std::cout << user->getName() << " was afflicted by " << this->status->GetName() << std::endl;
        }
    }
    user->Inven.RemoveItem(this, 1);
}