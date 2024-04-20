#pragma once

#include "item.h"
#include "RegularItems.h"
#include "Equipment.h"
#include "statustypes.h"
//AttackIem(Name, damage, price, canSpread, description)
//AttackItem(Name, damage, price, effect, chance, canSpread, description);
std::string rockDesc = "A simple rock to throw at enemies.";
std::string dartDesc = "Peruvian dart to throw at enemies. Has slight chance to poison.";
std::string throwingAxeDesc = "A small axe, perfect for throwing at enemies. Timber!";
std::string bombDesc = "A bomb with a big punch and wide range.";
std::string gorillaBombDesc = "A gorilla sized bomb with a big wallop. All opponents take massive damage.";
std::string bucketOfSludgeDesc = "A bucket of sludge and waste to throw at enemies.";
std::string oilDrumSludgeDesc = "A entire oil drum of sludge. How does it do no damage\?";
std::string fluteDesc = "A lovely wooden flute. Makes even the most hardcore beast fall asleep";
std::string toasterDesc = "A NAV-116 model toaster by ReynoldsTech. Good for throwing and making toast. Can paralyze opponents.";
std::string lightningBottleDesc = "Release a powerful lighting bolt to strike an enemy. A very effective attack and can cause paralysis. It\'s lightning in a bottle!";
AttackItem rock("Rock", 10, 2, false, rockDesc);
AttackItem dart("Dart", 15, 5, &poison, 2, false, dartDesc);
AttackItem throwingAxe("Throwing Axe", 20, 15, false, throwingAxeDesc);
AttackItem bomb("Bomb", 20, 25, true, bombDesc);
AttackItem gorillaBomb("Gorilla Bomb", 50, 80, true, gorillaBombDesc);
AttackItem bucketOfSludge("Bucket of Sludge", 0, 15, &poison, 4, false, bucketOfSludgeDesc);
AttackItem oilDrumOfSludge("Oil Drum of Sludge", 0, 50, &poison, 5, true, oilDrumSludgeDesc);
AttackItem flute("Flute", 0, 20, &sleep, 10, false, fluteDesc);
AttackItem toaster("Toaster", 15, 50, &paralysis, 5, false, toasterDesc);
AttackItem lightningBottle("Lightning in a Bottle", 50, 120, &paralysis, 8, false, lightningBottleDesc);

//HealItem(Name, healAmnt, price, description)
//HealItem(Name, healAmnt, price, status, description)
std::string waterDesc = "Clear water as pure as Ryan Reynolds. Heals moderately.";
std::string bananaDesc = "A nutrious, delicous banana. Stores health moderately.";
std::string elixirDesc = "strange liquid with the consistency of medicine but taste of milk. Heals greatly.";
std::string ectoplasmDesc = "Residue from a ghost. Seems able heal but the glow it gives is a bit offputting...";
std::string zombieBloodDesc = "Blood from a decaying corpse. 0/10, would not recommend";
std::string cookieDesc = "A delicous cookie. Not too good for health but healps";
std::string rubberFruitDesc = "Fruit with rubber-like flesh. Eating it cures paralysis.";
HealItem pureWater("Pure Water", 20, 9, &poison, waterDesc);
HealItem banana("Banana", 10, 5, bananaDesc);
HealItem ectoplasm("Ectoplasm", 25, 50, &paralysis, ectoplasmDesc);
HealItem zombieBlood("Zombie Blood", -10, 5, zombieBloodDesc);
HealItem elixir("Elixir", 40, 25, &poison, elixirDesc);
HealItem cookie("Cookie", 5, 3, cookieDesc);
HealItem rubberFruit("Rubber Fruit", 0, 15, &paralysis, rubberFruitDesc);

//StatusItem(name, boost, stat, price, description)
//StatusItem(name, boost, stat, price, Status, chance, description)
std::string roidsDesc = "Literal steroids bro";
std::string superRoidsDesc = "Even better steroids bro";
std::string anubisAmuletDesc = "An amulet dropped by mummies. Has an inscription of Anubis, the Egyptian god of death and supposed inventor of embalming";
std::string setAmuletDesc = "An amulet dropped by mummies. Has an inscription of Set, the Egyptian god who is the rival of Horus and got into conflict with Anubis";
std::string magicShieldDesc = "An artifact that temporally creates a magic sheild of energy around your body";
std::string sentryHeadDesc = "The head of a sentry. Its strength flows through your body";
std::string ninjaBandDesc = "The headband of a ninja. It causes you to put your arms straight behind you as you run, increasing your speed";
std::string cryptoHeartDesc = "The heart of a cryptogriph. A strange power from within makes your skin like steel";
std::string sleepingPillDesc = "A pill to help you fall asleep. Boosts StaticDef";
StatusItem roids("'Roids", 2, attack, 15, roidsDesc);
StatusItem superRoids("Super 'Roids", 15, attack, 60, &paralysis, 10, superRoidsDesc);
StatusItem anubisAmulet("Amulet of Anubis", 5, staticdef, 45, anubisAmuletDesc);
StatusItem setAmulet("Amulet of Set", 10, staticdef, 45, &poison, 10, setAmuletDesc);
StatusItem magicShield("Magic Shield", 5, percdef, 30, magicShieldDesc);
StatusItem sentryHead("Sentry Head", 10, attack, 50, sentryHeadDesc);
StatusItem ninjaBand("Ninja Band", 15, speed, 25, ninjaBandDesc);
StatusItem cryptoHeart("Cryptogriph Heart", 15, staticdef, 60, &paralysis, 4, cryptoHeartDesc);
StatusItem sleepingPill("Sleeping Pill", 9, staticdef, 15, &sleep, 10, sleepingPillDesc);



//Weapon(Name, durability, damageMultiplier, price, description)
std::string swordDesc = "A mighty sword, made of Grecian Iron.";
std::string spearDesc = "Light spear with a hard oak shaft.";
std::string hammerDesc = "A heavy hammer to impound heads with.";
std::string staffDesc = "An old staff. While it has seem better days, it still has use.";
std::string bottleDesc = "A broken bottle of beer. Great for dealing damage but easily broken.";
std::string goldSwordDesc = "A heavy sword made of solid gold. Not very durable but highly prized by merchants.";
std::string whipDesc = "a flexible and durable whip, handy to beat orphans.";
std::string undeadBladeDesc = "A sharp blade that reaks of death. Every second you hold it, the more it feels like the souls of the dead surround you";
std::string boneDesc = "A thick bone that seems to come from a femur. The bone looks oddly human-like.";
std::string katanaDesc = "A sharp, one-edged sword. So sharp, that even running your finger across it seems risky";
Weapon sword("Sword", 20, 1.25, 20, swordDesc);
Weapon spear("Spear", 10, 1.20, 15, spearDesc);
Weapon hammer("Gorilla Hammer", 30, 1.50, 45, hammerDesc);
Weapon staff("Staff", 10, 1.10, 8, staffDesc);
Weapon bottle("Broken Bottle", 3, 1.70, 4, bottleDesc);
Weapon goldSword("Gold Sword", 5, 1.2, 100, goldSwordDesc);
Weapon whip("Orphan Whip", 40, 1.2, 20, whipDesc);
Weapon undeadBlade("Undead Blade", 30, 1.30, 70, undeadBladeDesc);
Weapon bone("Bone", 10, 1.20, 10, boneDesc);
Weapon katana("Katana", 18, 1.4, 30, katanaDesc);


//Armor(Name, durability, percentageDef, staticDef, price, ArmorType (enum), description)
std::string steelHelmDesc = "A reliable steel helmet to protect you from concusions.";
std::string steelChestDesc = "Durable armor made of pure iron.";
std::string steelLeggDesc = "Steel leggings, great for defending you. Not very comfortable though...";
std::string steelBootsDesc = "Boots made of steel. It would be perfect for stomping on enemies but that is a different game.";

Armor steelHelm("Steel Helmet", 50, .2, 6, 30, Helmet, steelHelmDesc);
Armor steelChest("Steel Chestplate", 40, .4, 10, 50, Chestplate, steelChestDesc);
Armor steelLegg("Steel Leggins", 40, 6, .2, 40, Leggings, steelLeggDesc);
Armor steelBoots("Steel Boots", 50, 4, .2, 30, Boots, steelBootsDesc);

std::string chainHelmDesc = "A helmet made of chainmeal. Blocks high percentage of damage but does not have high upfront resistance.";
std::string chainChestDesc = "Chestplate made of chain links. Does not negate much damage but reduces amount taken greatly.";
std::string chainLeggDesc = "Leggins made of chainmeal. Good armor, just not very stylish though.";
std::string chainBootsDesc = "Boots made of chain. Just don\'t question it.";
Armor chainHelm("Chainmeal Helmet", 35, .20, 8, 25, Helmet, chainHelmDesc);
Armor chainChest("Chainmeal Chestplate", 35, .20, 8, 25, Chestplate, chainChestDesc);
Armor chainLegg("Chainmeal Leggings", 35, 20, .1, 25, Leggings, chainLeggDesc);
Armor chainBoots("Chainmeal Boots", 35, 20, .1, 25, Boots, chainBootsDesc);

std::string rockHelmDesc = "A rock helmet to protect your big brain.";
std::string rockChestDesc = "The name kind of says it all.";
std::string rockLeggDesc = "Don\'t even ask how you walk in these.";
std::string rockBootsDesc = "Impractical but effective.";
Armor rockHelm("Helmet Made Of Rocks", 10, .10, 16, 20, Helmet, rockHelmDesc);
Armor rockChest("Chestplate Made Of Rocks", 10, .10, 30, 20, Chestplate, rockChestDesc);
Armor rockLegg("Leggings Made Of Rocks", 15, .10, 8, 15, Leggings, rockLeggDesc);
Armor rockBoots("Shoes Made Of Rocks", 20, .05, 10, 14, Boots, rockBootsDesc);

std::string goldHelmDesc = "A nice and shiny helmet to protect your head. Too bad its stats are garbage.";
std::string goldChestDesc = "A weak chestplate made of gold. Rare and valuable.";
std::string goldLeggDesc = "May not be strong but it looks nice!";
std::string goldBootsDesc = "What it lacks in defense it makes up in drip.";
Armor goldHelm("Gold Armor", 15, .2, 5, 120, Helmet, goldHelmDesc);
Armor goldChest("Gold Armor", 15, .3, 5, 150, Chestplate, goldChestDesc);
Armor goldLegg("Gold Armor", 15, .2, 5, 100, Leggings, goldLeggDesc);
Armor goldBoots("Gold Armor", 15, .2, 5, 120, Boots, goldBootsDesc);

std::string vestDesc = "A tough and durable bulletproof vest.";
Armor toughVest("Tough Vest", 75, .15, 10, 30, Chestplate, vestDesc);

std::string baboomArmorDesc = "Rare armor that gives you the fighting spirit of a baboon.";
std::string armyVestDesc = "An bulletproof vest that has the Marines emblem on it. Increases manliness.";
std::string mBobArmorDesc = "With this armor, you will be coming for Monkey Bob. MAY PUTIN BE EVER IN YOUR FAVOR.";
Armor baboonArmor("Baboon Armor", 50, .4, 5, 25, 1.50, Chestplate, baboomArmorDesc);
Armor armyVest("Marine Vest", 75, .6, 10, 5, 1.40, Chestplate, armyVestDesc);
Armor monkeyBobArmor("Monkey Bob's Armor", 999999, .25, 25, 1.75, 350, Chestplate, mBobArmorDesc);
