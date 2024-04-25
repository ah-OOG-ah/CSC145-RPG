#pragma once

#include "Item.h"
#include "RegularItems.h"
#include "Equipment.h"
#include "statustypes.h"

namespace IDefs {

    //AttackIem(Name, damage, price, description, canSpread = false)
    //AttackItem(Name, damage, price, description, effect, chance, amount, canSpread = false);
    static const std::string rockDesc = "A simple rock to throw at enemies.";
    static const std::string dartDesc = "Peruvian dart to throw at enemies. Has slight chance to poison.";
    static const std::string throwingAxeDesc = "A small axe, perfect for throwing at enemies. Timber!";
    static const std::string bombDesc = "A bomb with a big punch and wide range.";
    static const std::string gorillaBombDesc = "A gorilla sized bomb with a big wallop. All opponents take massive damage.";
    static const std::string bucketOfSludgeDesc = "A bucket of sludge and waste to throw at enemies.";
    static const std::string oilDrumSludgeDesc = "A entire oil drum of sludge. How does it do no damage\?";
    static const std::string fluteDesc = "A lovely wooden flute. Makes even the most hardcore beast fall asleep";
    static const std::string toasterDesc = "A NAV-116 model toaster by ReynoldsTech. Good for throwing and making toast. Can paralyze opponents.";
    static const std::string lightningBottleDesc = "Release a powerful lighting bolt to strike an enemy. A very effective attack and can cause paralysis. It\'s lightning in a bottle!";
    static const auto rock = std::make_shared<AttackItem>("Rock", 10, 2, rockDesc);
    static const auto dart = std::make_shared<AttackItem>("Dart", 15, 5, dartDesc, &stypes::poison, 2);
    static const auto throwingAxe = std::make_shared<AttackItem>("Throwing Axe", 20, 15, throwingAxeDesc);
    static const auto bomb = std::make_shared<AttackItem>("Bomb", 20, 25, bombDesc, 1, true);
    static const auto gorillaBomb = std::make_shared<AttackItem>("Gorilla Bomb", 50, 80, gorillaBombDesc, 1, true);
    static const auto bucketOfSludge = std::make_shared<AttackItem>("Bucket of Sludge", 0, 15, bucketOfSludgeDesc, &stypes::poison, 4);
    static const auto oilDrumOfSludge = std::make_shared<AttackItem>("Oil Drum of Sludge", 0, 50, oilDrumSludgeDesc, &stypes::poison, 5, true);
    static const auto flute = std::make_shared<AttackItem>("Flute", 0, 20, fluteDesc, &stypes::sleep, 10);
    static const auto toaster = std::make_shared<AttackItem>("Toaster", 15, 50, toasterDesc, &stypes::paralysis, 5);
    static const auto lightningBottle = std::make_shared<AttackItem>("Lightning in a Bottle", 50, 120, lightningBottleDesc, &stypes::paralysis, 8);

    //HealItem(Name, healAmnt, price, description)
    //HealItem(Name, healAmnt, price, status, description)
    static const std::string waterDesc = "Clear water as pure as Ryan Reynolds. Heals moderately.";
    static const std::string bananaDesc = "A nutrious, delicous banana. Stores health moderately.";
    static const std::string elixirDesc = "strange liquid with the consistency of medicine but taste of milk. Heals greatly.";
    static const std::string ectoplasmDesc = "Residue from a ghost. Seems able heal but the glow it gives is a bit offputting...";
    static const std::string zombieBloodDesc = "Blood from a decaying corpse. 0/10, would not recommend";
    static const std::string cookieDesc = "A delicous cookie. Not too good for health but healps";
    static const std::string rubberFruitDesc = "Fruit with rubber-like flesh. Eating it cures paralysis.";
    static const auto pureWater = std::make_shared<HealItem>("Pure Water", 20, 9, waterDesc, &stypes::poison);
    static const auto banana = std::make_shared<HealItem>("Banana", 10, 5, bananaDesc);
    static const auto ectoplasm = std::make_shared<HealItem>("Ectoplasm", 25, 50, ectoplasmDesc, &stypes::paralysis);
    static const auto zombieBlood = std::make_shared<HealItem>("Zombie Blood", -10, 5, zombieBloodDesc);
    static const auto elixir = std::make_shared<HealItem>("Elixir", 40, 25, elixirDesc, &stypes::poison);
    static const auto cookie = std::make_shared<HealItem>("Cookie", 5, 3, cookieDesc);
    static const auto rubberFruit = std::make_shared<HealItem>("Rubber Fruit", 0, 15, rubberFruitDesc, &stypes::paralysis);

    //StatusItem(name, boost, stat, price, description)
    //StatusItem(name, boost, stat, price, Status, chance, description)
    static const std::string roidsDesc = "Literal steroids bro";
    static const std::string superRoidsDesc = "Even better steroids bro";
    static const std::string anubisAmuletDesc = "An amulet dropped by mummies. Has an inscription of Anubis, the Egyptian god of death and supposed inventor of embalming";
    static const std::string setAmuletDesc = "An amulet dropped by mummies. Has an inscription of Set, the Egyptian god who is the rival of Horus and got into conflict with Anubis";
    static const std::string magicShieldDesc = "An artifact that temporally creates a magic sheild of energy around your body";
    static const std::string sentryHeadDesc = "The head of a sentry. Its strength flows through your body";
    static const std::string ninjaBandDesc = "The headband of a ninja. It causes you to put your arms straight behind you as you run, increasing your speed";
    static const std::string cryptoHeartDesc = "The heart of a cryptogriph. A strange power from within makes your skin like steel";
    static const std::string sleepingPillDesc = "A pill to help you fall asleep. Boosts StaticDef";
    static const auto roids = std::make_shared<StatusItem>("'Roids", 15, 2, attack, roidsDesc);
    static const auto superRoids = std::make_shared<StatusItem>("Super 'Roids", 60, 15, attack, superRoidsDesc, &stypes::paralysis, 10);
    static const auto anubisAmulet = std::make_shared<StatusItem>("Amulet of Anubis", 45, 5, staticdef, anubisAmuletDesc);
    static const auto setAmulet = std::make_shared<StatusItem>("Amulet of Set", 45, 10, staticdef, setAmuletDesc, &stypes::poison, 10);
    static const auto magicShield = std::make_shared<StatusItem>("Magic Shield", 30, 5, percdef, magicShieldDesc);
    static const auto sentryHead = std::make_shared<StatusItem>("Sentry Head", 50, 10, attack, sentryHeadDesc);
    static const auto ninjaBand = std::make_shared<StatusItem>("Ninja Band", 25, 15, speed, ninjaBandDesc);
    static const auto cryptoHeart = std::make_shared<StatusItem>("Cryptogriph Heart", 60, 15, staticdef, cryptoHeartDesc, &stypes::paralysis, 4);
    static const auto sleepingPill = std::make_shared<StatusItem>("Sleeping Pill", 15, 9, staticdef, sleepingPillDesc, &stypes::sleep, 10);


    //Weapon(Name, durability, damageMultiplier, price, description)
    static const std::string swordDesc = "A mighty sword, made of Grecian Iron.";
    static const std::string spearDesc = "Light spear with a hard oak shaft.";
    static const std::string hammerDesc = "A heavy hammer to impound heads with.";
    static const std::string staffDesc = "An old staff. While it has seem better days, it still has use.";
    static const std::string bottleDesc = "A broken bottle of beer. Great for dealing damage but easily broken.";
    static const std::string goldSwordDesc = "A heavy sword made of solid gold. Not very durable but highly prized by merchants.";
    static const std::string whipDesc = "a flexible and durable whip, handy to beat orphans.";
    static const std::string undeadBladeDesc = "A sharp blade that reaks of death. Every second you hold it, the more it feels like the souls of the dead surround you";
    static const std::string boneDesc = "A thick bone that seems to come from a femur. The bone looks oddly human-like.";
    static const std::string katanaDesc = "A sharp, one-edged sword. So sharp, that even running your finger across it seems risky";
    static const auto sword = std::make_shared<Weapon>("Sword", 20, 1.25, 20, swordDesc);
    static const auto spear = std::make_shared<Weapon>("Spear", 10, 1.20, 15, spearDesc);
    static const auto hammer = std::make_shared<Weapon>("Gorilla Hammer", 30, 1.50, 45, hammerDesc);
    static const auto staff = std::make_shared<Weapon>("Staff", 10, 1.10, 8, staffDesc);
    static const auto bottle = std::make_shared<Weapon>("Broken Bottle", 3, 1.70, 4, bottleDesc);
    static const auto goldSword = std::make_shared<Weapon>("Gold Sword", 5, 1.2, 100, goldSwordDesc);
    static const auto whip = std::make_shared<Weapon>("Orphan Whip", 40, 1.2, 20, whipDesc);
    static const auto undeadBlade = std::make_shared<Weapon>("Undead Blade", 30, 1.30, 70, undeadBladeDesc);
    static const auto bone = std::make_shared<Weapon>("Bone", 10, 1.20, 10, boneDesc);
    static const auto katana = std::make_shared<Weapon>("Katana", 18, 1.4, 30, katanaDesc);


    //Armor(Name, durability, percentageDef, staticDef, price, ArmorType (enum), description)
    static const std::string steelHelmDesc = "A reliable steel helmet to protect you from concusions.";
    static const std::string steelChestDesc = "Durable armor made of pure iron.";
    static const std::string steelLeggDesc = "Steel leggings, great for defending you. Not very comfortable though...";
    static const std::string steelBootsDesc = "Boots made of steel. It would be perfect for stomping on enemies but that is a different game.";

    static auto steelHelm = std::make_shared<Armor>("Steel Helmet", 50, .2, 6, 30, Helmet, steelHelmDesc);
    static auto steelChest = std::make_shared<Armor>("Steel Chestplate", 40, .4, 10, 50, Chestplate, steelChestDesc);
    static auto steelLegg = std::make_shared<Armor>("Steel Leggins", 40, .2, 6, 40, Leggings, steelLeggDesc);
    static auto steelBoots = std::make_shared<Armor>("Steel Boots", 50, .2, 4, 30, Boots, steelBootsDesc);

    static const std::string chainHelmDesc = "A helmet made of chainmeal. Blocks high percentage of damage but does not have high upfront resistance.";
    static const std::string chainChestDesc = "Chestplate made of chain links. Does not negate much damage but reduces amount taken greatly.";
    static const std::string chainLeggDesc = "Leggins made of chainmeal. Good armor, just not very stylish though.";
    static const std::string chainBootsDesc = "Boots made of chain. Just don\'t question it.";
    static auto chainHelm = std::make_shared<Armor>("Chainmeal Helmet", 35, .20, 8, 25, Helmet, chainHelmDesc);
    static auto chainChest = std::make_shared<Armor>("Chainmeal Chestplate", 35, .20, 8, 25, Chestplate, chainChestDesc);
    static auto chainLegg = std::make_shared<Armor>("Chainmeal Leggings", 35, .1, 20, 25, Leggings, chainLeggDesc);
    static auto chainBoots = std::make_shared<Armor>("Chainmeal Boots", 35, .1, 20, 25, Boots, chainBootsDesc);

    static const std::string rockHelmDesc = "A rock helmet to protect your big brain.";
    static const std::string rockChestDesc = "The name kind of says it all.";
    static const std::string rockLeggDesc = "Don\'t even ask how you walk in these.";
    static const std::string rockBootsDesc = "Impractical but effective.";
    static auto rockHelm = std::make_shared<Armor>("Helmet Made Of Rocks", 10, .10, 16, 20, Helmet, rockHelmDesc);
    static auto rockChest = std::make_shared<Armor>("Chestplate Made Of Rocks", 10, .10, 30, 20, Chestplate, rockChestDesc);
    static auto rockLegg = std::make_shared<Armor>("Leggings Made Of Rocks", 15, .10, 8, 15, Leggings, rockLeggDesc);
    static auto rockBoots = std::make_shared<Armor>("Shoes Made Of Rocks", 20, .05, 10, 14, Boots, rockBootsDesc);

    static const std::string goldHelmDesc = "A nice and shiny helmet to protect your head. Too bad its stats are garbage.";
    static const std::string goldChestDesc = "A weak chestplate made of gold. Rare and valuable.";
    static const std::string goldLeggDesc = "May not be strong but it looks nice!";
    static const std::string goldBootsDesc = "What it lacks in defense it makes up in drip.";
    static auto goldHelm = std::make_shared<Armor>("Gold Armor", 15, .2, 5, 120, Helmet, goldHelmDesc);
    static auto goldChest = std::make_shared<Armor>("Gold Armor", 15, .3, 5, 150, Chestplate, goldChestDesc);
    static auto goldLegg = std::make_shared<Armor>("Gold Armor", 15, .2, 5, 100, Leggings, goldLeggDesc);
    static auto goldBoots = std::make_shared<Armor>("Gold Armor", 15, .2, 5, 120, Boots, goldBootsDesc);

    static const std::string vestDesc = "A tough and durable bulletproof vest.";
    static auto toughVest = std::make_shared<Armor>("Tough Vest", 75, .15, 10, 30, Chestplate, vestDesc);

    static const std::string baboomArmorDesc = "Rare armor that gives you the fighting spirit of a baboon.";
    static const std::string armyVestDesc = "An bulletproof vest that has the Marines emblem on it. Increases manliness.";
    static const std::string mBobArmorDesc = "With this armor, you will be coming for Monkey Bob. MAY PUTIN BE EVER IN YOUR FAVOR.";
    static auto baboonArmor = std::make_shared<Armor>("Baboon Armor", 50, .4, 5, 1.5, 25, Chestplate, baboomArmorDesc);
    static auto armyVest = std::make_shared<Armor>("Marine Vest", 75, .6, 10, 1.4, 5, Chestplate, armyVestDesc);
    static auto monkeyBobArmor = std::make_shared<Armor>("Monkey Bob's Armor", 999999, .25, 25, 1.75, 350, Chestplate, mBobArmorDesc);
}