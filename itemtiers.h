#pragma once

#include "itemlist.h"
#include <vector>

std::vector<RegularItem*> noItems = { nullptr };
std::vector<RegularItem*> basicItems = {&rock, &dart, &pureWater, &cookie, &elixir };
std::vector<RegularItem*> healItemsOnly = {&pureWater, &cookie, &elixir };
std::vector<RegularItem*> rocksOnly = { &rock} ;
std::vector<Weapon*> noWeapons = { nullptr };
std::vector<Weapon*> basicWeapons = {&sword, &spear, &whip, &staff};
std::vector<Weapon*> rareWeapons = {&sword, &hammer, &goldSword, &bottle};
std::vector<Weapon*> swordsOnly = {&sword, &goldSword };
std::vector<Armor*> noArmor = { nullptr };
std::vector<Armor*> basicArmor = {&steelHelm, &steelLegg, &chainChest, &chainBoots, &chainLegg, &chainHelm, &rockChest, &toughVest};
std::vector<Armor*> betterArmor = {&steelHelm, &steelChest, &steelLegg, &steelBoots, &goldChest, &goldBoots, &goldLegg, &goldHelm, &rockHelm, &rockChest, &rockLegg, &rockBoots, &toughVest, &armyVest};
std::vector<Armor*> topTierArmor = {&steelHelm, &armyVest, &toughVest, &steelChest, &baboonArmor, &steelLegg, &steelBoots};
std::vector<Armor*> chainSet = {&chainHelm, &chainChest, &chainLegg, &chainBoots };
std::vector<Armor*> steelSet = {&steelHelm, &steelChest, &steelLegg, &steelBoots };
std::vector<Armor*> goldSet = {&goldHelm, &goldChest, &goldLegg, &goldBoots };
std::vector<Armor*> rockSet = {&rockHelm, &rockChest, &rockLegg, &rockBoots };