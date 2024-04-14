#include <string>
#include <utility>
#include "RegularItems.h"

RegularItem::RegularItem(std::string itemName, int64_t price) : RegularItem(std::move(itemName), price, 1) {}
RegularItem::RegularItem(std::string itemName, int64_t price, int64_t amnt)
    : Item(std::move(itemName), price, amnt, "FIXME") {}

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

void AttackItem::SetDamage(int64_t dmg) { damage = dmg; }
void AttackItem::SetStatus(Status* effect) { status = effect; }
void AttackItem::SetChance(int64_t chance) { effectChance = chance; }

int64_t AttackItem::GetDamage() const { return damage; }
Status* AttackItem::GetStatus() { return status; }
int64_t AttackItem::GetChance() const { return effectChance; }

HealItem::HealItem(std::string itemName, int64_t hp, int64_t price) : RegularItem(std::move(itemName), price) {
    hpAmnt = hp;
}
HealItem::HealItem(std::string itemName, int64_t hp, int64_t price, int64_t amnt) : RegularItem(std::move(itemName), price, amnt) {
    hpAmnt = hp;
}

void HealItem::SetHpAmnt(int64_t hp) { hpAmnt = hp; }
void HealItem::SetHealedStatus(Status* status) { healedStatus = status; }

int64_t HealItem::GetHpAmnt() const { return hpAmnt; }
Status* HealItem::GetHealedStatus() { return healedStatus; }

NonConsumAttackItem::NonConsumAttackItem(std::string itemName, int64_t dmg, int64_t price, Status* effect, int64_t chance)
    : AttackItem(std::move(itemName), dmg, price, effect, chance) {
    stackable = false;
}

NonConsumAttackItem::NonConsumAttackItem(std::string itemName, int64_t dmg, int64_t price)
    : AttackItem(std::move(itemName), dmg, price) {
    stackable = false;
}

std::string NonConsumAttackItem::GetAmntText() { return " "; }