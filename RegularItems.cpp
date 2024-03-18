#include <string>
#include <utility>
#include "RegularItems.h"

RegularItem::RegularItem(std::string itemName, int64_t amnt, int64_t price) : Item(std::move(itemName), amnt, price) {}
RegularItem::RegularItem(std::string itemName, int64_t amnt) : Item(std::move(itemName), amnt) {}
RegularItem::RegularItem(std::string itemName) : Item(std::move(itemName)) { }

std::string RegularItem::GetAmntText()
{
    return "x";
}

AttackItem::AttackItem(std::string itemName, int64_t amnt, int64_t dmg, int64_t price, Status* effect, int64_t chance) : RegularItem(itemName, amnt, price)
{
    damage = dmg;
    status = effect;
    effctChance = chance;
}

AttackItem::AttackItem(std::string itemName, int64_t amnt, int64_t dmg, int64_t price) : RegularItem(itemName, amnt, price)
{
    damage = dmg;
}

AttackItem::AttackItem(std::string itemName, int64_t amnt, int64_t dmg) : RegularItem(itemName, amnt)
{
    damage = dmg;
}

AttackItem::AttackItem(std::string itemName, int64_t dmg) : RegularItem(itemName)
{
    damage = dmg;
}

void AttackItem::SetDamage(int64_t dmg) { damage = dmg; }
void AttackItem::SetStatus(Status* effect) { status = effect; }
void AttackItem::SetChance(int64_t chance) { effctChance = chance; }

int64_t AttackItem::GetDamage() { return damage; }
Status* AttackItem::GetStatus() { return status; }
int64_t AttackItem::GetChance() { return effctChance; }

void HealItem::SetHpAmnt(int64_t hp) { hpAmnt = hp; }
void HealItem::SetHealedStatus(Status* status) { healedStatus = status; }

HealItem::HealItem(std::string itemName, int64_t amnt, int64_t hp, int64_t price, Status* status) : RegularItem(itemName, amnt, price)
{
    hpAmnt = hp;
    healedStatus = status;
}

HealItem::HealItem(std::string itemName, int64_t amnt, int64_t hp, int64_t price) : RegularItem(itemName, amnt, price)
{
    hpAmnt = hp;
}

HealItem::HealItem(std::string itemName, int64_t amnt, int64_t hp) : RegularItem(itemName, amnt)
{
    hpAmnt = hp;
}

HealItem::HealItem(std::string itemName, int64_t hp) : RegularItem(itemName)
{
    hpAmnt = hp;
}

int64_t HealItem::GetHpAmnt() { return hpAmnt; }
Status* HealItem::GetHealedStatus() { return healedStatus; }

NonConsumAttackItem::NonConsumAttackItem(std::string itemName, int64_t dmg, Status* effect, int64_t chance) : AttackItem(itemName, 1, dmg, 0, effect, chance) {}

NonConsumAttackItem::NonConsumAttackItem(std::string itemName, int64_t dmg) : AttackItem(itemName, 1, dmg) {}

void NonConsumAttackItem::ChangeAmount(int64_t addAmnt) { return; }

std::string NonConsumAttackItem::GetAmntText() { return " "; }