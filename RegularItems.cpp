#include <string>
#include <utility>
#include "RegularItems.h"

RegularItem(std::string itemName, int64_t price, int64_t amnt) : Item(itemName, price, amnt) {}
RegularItem(std::string itemName, int64_t price) : Item(itemName, price) {}

std::string RegularItem::GetAmntText()
{
    return "x";
}

AttackItem(std::string itemName, int64_t dmg, int64_t price, Status* effect, int64_t chance) : RegularItem(itemName, price) 
{
    damage = dmg;
    status = effect;
    effectChance = chance;
}
AttackItem(std::string itemName, int64_t dmg, int64_t price, int64_t amnt) : RegularItem(itemName, price, amnt)
{
    damage = dmg;
}
AttackItem(std::string itemName, int64_t dmg, int64_t price) : RegularItem(itemName, price)
{
    damage = dmg;
}

void AttackItem::SetDamage(int64_t dmg) { damage = dmg; }
void AttackItem::SetStatus(Status* effect) { status = effect; }
void AttackItem::SetChance(int64_t chance) { effectChance = chance; }

int64_t AttackItem::GetDamage() { return damage; }
Status* AttackItem::GetStatus() { return status; }
int64_t AttackItem::GetChance() { return effectChance; }

HealItem(std::string itemName, int64_t hp, int64_t price) : RegularItem(itemName, price)
{
    hpAmnt = hp;
}
HealItem(std::string itemName, int64_t hp, int64_t price, int64_t amnt) : RegularItem(itemName, price, amnt)
{
    hpAmnt = hp;
}

void HealItem::SetHpAmnt(int64_t hp) { hpAmnt = hp; }
void HealItem::SetHealedStatus(Status* status) { healedStatus = status; }

int64_t HealItem::GetHpAmnt() { return hpAmnt; }
Status* HealItem::GetHealedStatus() { return healedStatus; }

NonConsumAttackItem::NonConsumAttackItem(std::string itemName, int64_t dmg, int64_t price, Status* effect, int64_t chance) : AttackItem(itemName, dmg, price, effect, chance) {}

NonConsumAttackItem::NonConsumAttackItem(std::string itemName, int64_t dmg, int64_t price) : AttackItem(itemName, dmg, price) {}

void NonConsumAttackItem::ChangeAmount(int64_t addAmnt) { return; }

std::string NonConsumAttackItem::GetAmntText() { return " "; }