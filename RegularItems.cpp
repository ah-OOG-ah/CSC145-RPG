#include <cstdint>
#include <string>
#include "RegularItems.h"

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

void AttackItem::SetDamage(int64_t dmg) { damage = dmg; }
void AttackItem::SetStatus(Status* effect) { status = effect; }
void AttackItem::SetChance(int64_t chance) { effctChance = chance; }

int64_t AttackItem::GetDamage() { return damage; }
Status* AttackItem::GetStatus() { return status; }
int64_t AttackItem::GetChance() { return effctChance; }