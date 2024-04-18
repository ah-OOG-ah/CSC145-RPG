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

AttackItem::AttackItem(std::string itemName, int64_t dmg, int64_t price, Status* effect, int64_t chance) : RegularItem(std::move(itemName), price) {
    damage = dmg;
    status = effect;
    effectChance = chance;
}
AttackItem::AttackItem(std::string itemName, int64_t dmg, int64_t price, int64_t amnt) : RegularItem(std::move(itemName), price, amnt) {
    damage = dmg;
}
AttackItem::AttackItem(std::string itemName, int64_t dmg, int64_t price) : RegularItem(std::move(itemName), price) {
    damage = dmg;
}
//Constructors with descriptions
AttackItem::AttackItem(std::string itemName, int64_t dmg, int64_t price, Status* effect, int64_t chance, std::string desc) : RegularItem(std::move(itemName), price, std::move(desc)) {
    damage = dmg;
    status = effect;
    effectChance = chance;
}
AttackItem::AttackItem(std::string itemName, int64_t dmg, int64_t price, int64_t amnt, std::string desc) : RegularItem(std::move(itemName), price, amnt, std::move(desc)) {
    damage = dmg;
}
AttackItem::AttackItem(std::string itemName, int64_t dmg, int64_t price, std::string desc) : RegularItem(std::move(itemName), price, std::move(desc)) {
    damage = dmg;
}
AttackItem::AttackItem(AttackItem* at) : RegularItem(at)
{
    this->damage = at->GetDamage();
}

void AttackItem::SetDamage(int64_t dmg) { damage = dmg; }
void AttackItem::SetStatus(Status* effect) { status = effect; }
void AttackItem::SetChance(int64_t chance) { effectChance = chance; }

int64_t AttackItem::GetDamage() const { return damage; }
Status* AttackItem::GetStatus() { return status; }
int64_t AttackItem::GetChance() const { return effectChance; }

void AttackItem::display()
{
    std::cout << entries[0] << std::endl;
    std::cout << "Price: " << this->GetPrice() << std::endl;
    std::cout << "Damage: " << this->GetDamage() << std::endl;
    std::cout << entries[1] << std::endl;
    std::cout << "Enter any key to exit " << std::endl;
    std::string choice;
    std::getline(std::cin, choice);
    return;
}

void AttackItem::Use(Entity* user, Entity* opponent)
{
    opponent->changeHP(-1 * this->GetDamage());
    user->Inven.RemoveItem(user->Inven.GetPos(this), 1);
    std::cout << user->getName() << " used " << this->GetName() << std::endl;
    std::cout << opponent->getName() << " took " << this->GetDamage() << " damage " << std::endl;
}

HealItem::HealItem(std::string itemName, int64_t hp, int64_t price) : RegularItem(std::move(itemName), price) {
    hpAmnt = hp;
}
HealItem::HealItem(std::string itemName, int64_t hp, int64_t price, int64_t amnt) : RegularItem(std::move(itemName), price, amnt) {
    hpAmnt = hp;
}
//Constructors with descriptions
HealItem::HealItem(std::string itemName, int64_t hp, int64_t price, std::string desc) : RegularItem(std::move(itemName), price, std::move(desc)) {
    hpAmnt = hp;
}
HealItem::HealItem(std::string itemName, int64_t hp, int64_t price, int64_t amnt, std::string desc) : RegularItem(std::move(itemName), price, amnt, std::move(desc)) {
    hpAmnt = hp;
}
HealItem::HealItem(HealItem* ht) : RegularItem(ht)
{
    this->hpAmnt = ht->GetHpAmnt();
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
    std::cout << "Amount: " << this->GetAmount() << this->GetAmntText() << std::endl;
    std::cout << entries[1] << std::endl;
    std::cout << "Enter EXIT to exit or HEAL to heal with this item" << std::endl;
    std::string choice;
    while(choice != "EXIT")
    {
        std::getline(std::cin, choice);
        if(choice == "HEAL") 
        {
            this->Use(getPlayer().get(), nullptr);
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

void HealItem::Use(Entity* user, Entity* opponent)
{
    user->changeHP(this->GetHpAmnt());
    user->Inven.RemoveItem(user->Inven.GetPos(this), 1);
    std::cout << user->getName() << " used " << this->GetName() << std::endl;
    std::cout << user->getName() << " HP was restored by " << this->GetHpAmnt() << "HP" << std::endl;
}

StatusItem::StatusItem(std::string itemName, int64_t boost, statBoost stat, int64_t price, Status* effect, int64_t chance) : StatusItem(itemName, boost, stat, price, effect, chance, "NONE") {}

StatusItem::StatusItem(std::string itemName, int64_t boost, statBoost stat, int64_t price, int64_t amnt) : StatusItem(itemName, boost, stat, price, amnt, "NONE") {}
StatusItem::StatusItem(std::string itemName, int64_t boost, statBoost stat, int64_t price) : StatusItem(itemName, boost, stat, price, "NONE") {}
//Constructors with descriptions
StatusItem::StatusItem(std::string itemName, int64_t boost, statBoost stat, int64_t price, Status* effect, int64_t chance, std::string desc) : RegularItem(itemName, price, desc)
{
    this->boost = boost;
    this->stat = stat;
    this->status = effect;
    this->effectChance = chance;
}
StatusItem::StatusItem(std::string itemName, int64_t boost, statBoost stat, int64_t price, int64_t amnt, std::string desc) : RegularItem(itemName, price, amnt, desc)
{
    this->boost = boost;
    this->stat = stat;
}
StatusItem::StatusItem(std::string itemName, int64_t boost, statBoost stat, int64_t price, std::string desc) : RegularItem(itemName, price, desc)
{
    this->boost = boost;
    this->stat = stat;
}
StatusItem::StatusItem(StatusItem* st) : RegularItem(st)
{
    this->boost =st->boost;
    this->stat = st->stat;
    this->status = st->status;
    this->effectChance = st->effectChance;
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
    std::cout << "Boosts: " << this->GetStat() << std::endl;
    std::cout << "Boost Amount: " << this->GetBoost() << std::endl;
    std::cout << "Amount: " << this->GetAmount() << this->GetAmntText() << std::endl;
    std::cout << entries[1] << std::endl;
    std::cout << "Enter any key to exit " << std::endl;
    std::string choice;
    std::getline(std::cin, choice);
    return;
}

void StatusItem::Use(Entity* user, Entity* opponent)
{
    return; //Exact implementation awaits
}

NonConsumAttackItem::NonConsumAttackItem(std::string itemName, int64_t dmg, int64_t price, Status* effect, int64_t chance)
    : AttackItem(std::move(itemName), dmg, price, effect, chance) {
    stackable = false;
}

NonConsumAttackItem::NonConsumAttackItem(std::string itemName, int64_t dmg, int64_t price)
    : AttackItem(std::move(itemName), dmg, price) {
    stackable = false;
}
//Constructors with descriptions
NonConsumAttackItem::NonConsumAttackItem(std::string itemName, int64_t dmg, int64_t price, Status* effect, int64_t chance, std::string desc)
    : AttackItem(std::move(itemName), dmg, price, effect, chance, std::move(desc)) {
    this->stackable = false;
}
NonConsumAttackItem::NonConsumAttackItem(std::string itemName, int64_t dmg, int64_t price, std::string desc)
    : AttackItem(std::move(itemName), dmg, price, std::move(desc)) {
    this->stackable = false;
}
NonConsumAttackItem::NonConsumAttackItem(NonConsumAttackItem* ncat) : AttackItem(ncat)
{
    this->stackable = false;
}

std::string NonConsumAttackItem::GetAmntText() { return " "; }