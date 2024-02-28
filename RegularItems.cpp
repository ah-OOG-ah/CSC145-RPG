#include <cstdint>
#include <string>
#include "RegularItems.h"

RegularItem::RegularItem(std::string itemName, int64_t amnt) : Item(itemName, amnt) {}
RegularItem::RegularItem(std::string itemName) : Item(itemName) { }

std::string RegularItem::GetAmntText()
{
    return uses;
}

AttackItem::AttackItem(std::string itemName, int64_t amnt, int64_t dmg, Status* effect, int64_t chance) : RegularItem(itemName, amnt)
{
    damage = dmg;
    status = effect;
    effctChance = chance;
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

HealItem::HealItem(std::string itemName, int64_t amnt, int64_t hp, Status* status) : RegularItem(itemName, amnt)
{
    hpAmnt = hp;
    healedStatus = status;
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

NonConsumAttackItem::NonConsumAttackItem(std::string itemName, int64_t dmg, Status* effect, int64_t chance) : AttackItem(itemName, 1, dmg, effect, chance)
{
    uses = " ";
}

void NonConsumAttackItem::ChangeAmount(int64_t addAmnt) { return; }