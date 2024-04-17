#pragma once

#include "itemlist.h"
#include <vector>

std::vector<RegularItem*> basicItems = {&rock, &dart, &pureWater, &cookie, &elixir };
std::vector<Weapon*> basicWeapons = {&sword, &spear, &whip, &staff};
std::vector<Weapon*> rareWeapons = {&sword, &hammer, &goldSword, &bottle};
std::vector<Armor*> basicArmor = {&steelHelm, &steelLegg, &chainChest, &chainBoots, &chainLegg, &chainHelm, &rockChest, &toughVest};
std::vector<Armor*> betterArmor = {&steelHelm, &steelChest, &steelLegg, &steelBoots, &goldChest, &goldBoots, &goldLegg, &goldHelm, &rockHelm, &rockChest, &rockLegg, &rockBoots, &toughVest, &armyVest};
std::vector<Armor*> topTierArmor = {&steelHelm, &armyVest, &toughVest, &steelChest, &baboonArmor, &steelLegg, &steelBoots};