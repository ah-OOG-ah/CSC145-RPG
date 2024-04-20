#pragma once

#include "itemlist.h"
#include <vector>

std::vector<AttackItem> noAttk = {};
std::vector<HealItem> noHeal = {};
std::vector<StatusItem> noStatusItems = {};
std::vector<AttackItem> bombsOnly = {bomb, bomb, gorillaBomb, nullptr };
std::vector<AttackItem> powerfulAttkItems = { gorillaBomb, gorillaBomb, oilDrumOfSludge, lightningBottle};
std::vector<AttackItem> basicAttkItems = { rock, rock, dart, dart};
std::vector<AttackItem> betterAttkItems = {throwingAxe, bomb, throwingAxe, bomb, gorillaBomb, flute, bucketOfSludge};
std::vector<StatusItem> mummyItems = {anubisAmulet, anubisAmulet, setAmulet };
std::vector<StatusItem> shieldOnly = { magicShield };
std::vector<HealItem> basicHealItems = { pureWater, cookie, cookie, cookie, banana, banana };
std::vector<AttackItem> greatAttkItems = {throwingAxe, gorillaBomb, toaster, bucketOfSludge, oilDrumOfSludge };
std::vector<AttackItem> poisonItems = { bucketOfSludge, bucketOfSludge, oilDrumOfSludge };
std::vector<HealItem> betterHealItems = { elixir, elixir, pureWater, pureWater, rubberFruit };
std::vector<StatusItem> basicRoids = { roids};
std::vector<StatusItem> allRoids = { roids, roids, superRoids};
std::vector<StatusItem> goodStatusItems = { ninjaBand, superRoids, magicShield };
std::vector<StatusItem> sleepingPillsOnly = { sleepingPill };
std::vector<AttackItem> rocksOnly = { rock};
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
