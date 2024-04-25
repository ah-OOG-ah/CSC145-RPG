#pragma once

#include "ItemDefs.h"
#include <vector>


namespace ITiers {

    using namespace IDefs;

    /**
     * ITEMS
     */

    // Attack items
    static const std::vector<std::shared_ptr<Item>> noAttk { };
    static const std::vector<std::shared_ptr<Item>> basicAttkItems { rock, rock, dart, dart };
    static const std::vector<std::shared_ptr<Item>> betterAttkItems { throwingAxe, bomb, throwingAxe, bomb, gorillaBomb, flute, bucketOfSludge };
    static const std::vector<std::shared_ptr<Item>> greatAttkItems { throwingAxe, gorillaBomb, toaster, bucketOfSludge, oilDrumOfSludge };
    static const std::vector<std::shared_ptr<Item>> powerfulAttkItems { gorillaBomb, gorillaBomb, oilDrumOfSludge, lightningBottle };

    // Special sets
    static const std::vector<std::shared_ptr<Item>> rocksOnly {rock};
    static const std::vector<std::shared_ptr<Item>> bombsOnly { bomb, bomb, gorillaBomb };
    static const std::vector<std::shared_ptr<Item>> poisonItems { bucketOfSludge, bucketOfSludge, oilDrumOfSludge };

    // Healing
    static const std::vector<std::shared_ptr<Item>> noHeal = { };
    static const std::vector<std::shared_ptr<Item>> basicHealItems { pureWater, cookie, cookie, cookie, banana, banana };
    static const std::vector<std::shared_ptr<Item>> betterHealItems {elixir, elixir, pureWater, pureWater, rubberFruit};

    // Status items
    static const std::vector<std::shared_ptr<Item>> noStatusItems = { };
    static const std::vector<std::shared_ptr<Item>> goodStatusItems {ninjaBand, superRoids, magicShield};

    // Special sets
    static const std::vector<std::shared_ptr<Item>> shieldOnly { magicShield };
    static const std::vector<std::shared_ptr<Item>> sleepingPillsOnly {sleepingPill};
    static const std::vector<std::shared_ptr<Item>> mummyItems { anubisAmulet, anubisAmulet, setAmulet };
    static const std::vector<std::shared_ptr<Item>> basicRoids { roids };
    static const std::vector<std::shared_ptr<Item>> allRoids { roids, roids, superRoids };

    /**
     * EQUIPMENT
     */

    // Weapons
    static const std::vector<std::shared_ptr<Weapon>> noWeapons = { nullptr };
    static const std::vector<std::shared_ptr<Weapon>> basicWeapons = { sword, spear, whip, staff, nullptr };
    static const std::vector<std::shared_ptr<Weapon>> rareWeapons = { katana, hammer, goldSword, bottle };

    // Special sets
    static const std::vector<std::shared_ptr<Weapon>> swordsOnly = { sword, sword, sword, sword, katana, goldSword };
    static const std::vector<std::shared_ptr<Weapon>> undeadWeapons = { undeadBlade, bone, bone };

    // Full armors
    static const ArmorSet noArmor{};
    static const ArmorSet chainSet = {chainHelm, chainChest, chainLegg, chainBoots };
    static const ArmorSet steelSet = {steelHelm, steelChest, steelLegg, steelBoots };
    static const ArmorSet goldSet = {goldHelm, goldChest, goldLegg, goldBoots };
    static const ArmorSet rockSet = {rockHelm, rockChest, rockLegg, rockBoots };

    // Armor pools
    static const std::vector<std::shared_ptr<Armor>> basicArmor = { steelHelm, chainChest, chainBoots, chainLegg, chainHelm, rockChest, toughVest };
    static const std::vector<std::shared_ptr<Armor>> betterArmor = { steelHelm, steelChest, steelLegg, steelBoots, goldChest, goldBoots, goldLegg, goldHelm, rockHelm, rockChest, rockLegg, rockBoots, toughVest, armyVest };
    static const std::vector<std::shared_ptr<Armor>> topTierArmor = { steelHelm, armyVest, toughVest, steelChest, baboonArmor, steelLegg, steelBoots };

}