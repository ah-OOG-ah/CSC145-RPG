#pragma once

#include "itemlist.h"
#include <vector>

std::vector<RegularItem*> noItems = { nullptr };
std::vector<RegularItem*> bombsOnly = {&bomb, &bomb, &gorillaBomb, nullptr };
std::vector<RegularItem*> gorillaBombOnly = { &gorillaBomb };
std::vector<RegularItem*> basicItems = {&rock, &rock, &dart, &dart, &pureWater, &cookie, &banana };
std::vector<RegularItem*> betterItems = {&throwingAxe, &bomb, &throwingAxe, &bomb, &elixir, &gorillaBomb, &roids, &roids, &ninjaBand};
std::vector<RegularItem*> mummyItems = {&amulet, &amulet, &elixir};
std::vector<RegularItem*> sentryItems = {&bomb, nullptr, &magicShield, &magicShield };
std::vector<RegularItem*> healItemsOnly = {&pureWater, &cookie, &pureWater, &banana, &elixir, &banana };
std::vector<RegularItem*> rocksOnly = { &rock} ;
std::vector<Weapon*> noWeapons = { nullptr };
std::vector<Weapon*> basicWeapons = {&sword, &spear, &whip, &staff, nullptr};
std::vector<Weapon*> rareWeapons = {&katana, &hammer, &goldSword, &bottle};
std::vector<Weapon*> swordsOnly = {&sword, &sword, &sword, &sword, &katana, &goldSword };
std::vector<Weapon*> undeadWeapons = {&undeadBlade, &bone, &bone };
std::vector<Armor*> noArmor = { nullptr };
std::vector<Armor*> basicArmor = {&steelHelm, nullptr, &chainChest, &chainBoots, &chainLegg, &chainHelm, &rockChest, &toughVest};
std::vector<Armor*> betterArmor = {&steelHelm, &steelChest, &steelLegg, &steelBoots, &goldChest, &goldBoots, &goldLegg, &goldHelm, &rockHelm, &rockChest, &rockLegg, &rockBoots, &toughVest, &armyVest};
std::vector<Armor*> topTierArmor = {&steelHelm, &armyVest, &toughVest, &steelChest, &baboonArmor, &steelLegg, &steelBoots};
std::vector<Armor*> chainSet = {&chainHelm, &chainChest, &chainLegg, &chainBoots };
std::vector<Armor*> steelSet = {&steelHelm, &steelChest, &steelLegg, &steelBoots };
std::vector<Armor*> goldSet = {&goldHelm, &goldChest, &goldLegg, &goldBoots };
std::vector<Armor*> rockSet = {&rockHelm, &rockChest, &rockLegg, &rockBoots };