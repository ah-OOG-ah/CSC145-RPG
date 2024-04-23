#pragma once

#include "ItemDefs.h"
#include <vector>


namespace ITiers {

    using namespace IDefs;

    static const std::vector<AttackItem> noAttk = {};
    static const std::vector<HealItem> noHeal = {};
    static const std::vector<StatusItem> noStatusItems = {};
    static const std::vector<AttackItem> bombsOnly = {bomb, bomb, gorillaBomb};
    static const std::vector<AttackItem> powerfulAttkItems = {gorillaBomb, gorillaBomb, oilDrumOfSludge, lightningBottle};
    static const Inventory basicAttkItems({rock, rock, dart, dart});
    static const std::vector<AttackItem> betterAttkItems = {throwingAxe, bomb, throwingAxe, bomb, gorillaBomb, flute,
                                               bucketOfSludge};
    static const Inventory mummyItems({anubisAmulet, anubisAmulet, setAmulet});
    static const Inventory shieldOnly({magicShield});
    static const std::vector<HealItem> basicHealItems = {pureWater, cookie, cookie, cookie, banana, banana};
    static const std::vector<AttackItem> greatAttkItems = {throwingAxe, gorillaBomb, toaster, bucketOfSludge, oilDrumOfSludge};
    static const std::vector<AttackItem> poisonItems = {bucketOfSludge, bucketOfSludge, oilDrumOfSludge};
    static const std::vector<HealItem> betterHealItems = {elixir, elixir, pureWater, pureWater, rubberFruit};
    static const Inventory basicRoids({roids});
    static const Inventory allRoids({ roids, roids, superRoids });
    static const Inventory goodStatusItems({ninjaBand, superRoids, magicShield});
    static const Inventory sleepingPillsOnly({sleepingPill});
    static const Inventory rocksOnly({rock});
    static const std::vector<Weapon *> noWeapons = {nullptr};
    static const std::vector<Weapon *> basicWeapons = {&sword, &spear, &whip, &staff, nullptr};
    static const std::vector<Weapon *> rareWeapons = {&katana, &hammer, &goldSword, &bottle};
    static const std::vector<Weapon *> swordsOnly = {&sword, &sword, &sword, &sword, &katana, &goldSword};
    static const std::vector<Weapon *> undeadWeapons = {&undeadBlade, &bone, &bone};
    static const ArmorSet noArmor{};
    static const std::vector<Armor *> basicArmor = {&steelHelm, nullptr, &chainChest, &chainBoots, &chainLegg, &chainHelm,
                                       &rockChest, &toughVest};
    static const std::vector<Armor *> betterArmor = {&steelHelm, &steelChest, &steelLegg, &steelBoots, &goldChest, &goldBoots,
                                        &goldLegg, &goldHelm, &rockHelm, &rockChest, &rockLegg, &rockBoots, &toughVest,
                                        &armyVest};
    static const std::vector<Armor *> topTierArmor = {&steelHelm, &armyVest, &toughVest, &steelChest, &baboonArmor, &steelLegg,
                                         &steelBoots};
    static const std::vector<Armor *> chainSet = {&chainHelm, &chainChest, &chainLegg, &chainBoots};
    static const std::vector<Armor *> steelSet = {&steelHelm, &steelChest, &steelLegg, &steelBoots};
    static const std::vector<Armor *> goldSet = {&goldHelm, &goldChest, &goldLegg, &goldBoots};
    static const std::vector<Armor *> rockSet = {&rockHelm, &rockChest, &rockLegg, &rockBoots};
}