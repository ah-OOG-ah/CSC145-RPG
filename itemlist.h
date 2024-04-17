#include "item.h"
#include "RegularItems.h"
#include "Equipment.h"
//AttackIem(Name, damage, price, description)
std::string rockDesc = "A simple rock to throw at enemies.";
std::string dartDesc = "Peruvian dart to throw at enemies.";
AttackItem rock("Rock", 5, 2, rockDesc);
AttackItem dart("Dart", 8, 5, dartDesc);

//HealItem(Name, healAmnt, price, description)
std::string waterDesc = "Clear water as pure as Ryan Reynolds. Heals moderately.";
std::string elixirDesc = "strange liquid with the consistency of medicine but taste of milk. Heals greatly.";
std::string cookieDesc = "A delicous cookie. Not too good for health but healps";
HealItem pureWater("Pure Water", 15, 9, waterDesc);
HealItem elixir("Elixir", 40, 25, elixirDesc);
HealItem cookie("Cookie", 5, 3, cookieDesc);

//Weapon(Name, durability, damageMultiplier, price, description)
std::string swordDesc = "A mighty sword, made of Grecian Iron.";
std::string spearDesc = "Light spear with a hard oak shaft.";
std::string hammerDesc = "A heavy hammer to impound heads with.";
std::string staffDesc = "An old staff. While it has seem better days, it still has use.";
std::string bottleDesc = "A broken bottle of beer. Great for dealing damage but easily broken.";
std::string goldSwordDesc = "A heavy sword made of solid gold. Not very durable but highly prized by merchants.";
std::string whipDesc = "a flexible and durable whip, handy to beat orphans.";
Weapon sword("Sword", 20, 25, 20, swordDesc);
Weapon spear("Spear", 10, 20, 15, spearDesc);
Weapon hammer("Gorilla Hammer", 30, 50, 45, hammerDesc);
Weapon staff("Staff", 10, 10, 8, staffDesc);
Weapon bottle("Broken Bottle", 3, 70, 4, bottleDesc);
Weapon goldSword("Gold Sword", 5, 50, 100, goldSwordDesc);
Weapon whip("Orphan Whip", 40, 5, 20, whipDesc);

//Armor(Name, durability, percentageDef, staticDef, price, ArmorType (enum), description)
std::string steelHelmDesc = "A reliable steel helmet to protect you from concusions.";
std::string steelChestDesc = "Durable armor made of pure iron.";
std::string steelLeggDesc = "Steel leggings, great for defending you. Not very comfortable though...";
std::string steelBootsDesc = "Boots made of steel. It would be perfect for stomping on enemies but that is a different game.";

Armor steelHelm("Steel Helmet", 50, 4, 6, 30, Helmet, steelHelmDesc);
Armor steelChest("Steel Chestplate", 40, 8, 10, 50, Chestplate, steelChestDesc);
Armor steelLegg("Steel Leggins", 40, 6, 8, 40, Leggings, steelLeggDesc);
Armor steelBoots("Steel Boots", 50, 4, 4, 30, Boots, steelBootsDesc);

std::string chainHelmDesc = "A helmet made of chainmeal. Blocks high percentage of damage but does not have high upfront resistance.";
std::string chainChestDesc = "Chestplate made of chain links. Does not negate much damage but reduces amount taken greatly.";
std::string chainLeggDesc = "Leggins made of chainmeal. Good armor, just not very stylish though.";
std::string chainBootsDesc = "Boots made of chain. Just don\'t question it.";
Armor chainHelm("Chainmeal Helmet", 35, 20, 8, 25, Helmet, chainHelmDesc);
Armor chainChest("Chainmeal Chestplate", 35, 20, 8, 25, Chestplate, chainChestDesc);
Armor chainLegg("Chainmeal Leggings", 35, 20, 8, 25, Leggings, chainLeggDesc);
Armor chainBoots("Chainmeal Boots", 35, 20, 8, 25, Boots, chainBootsDesc);

std::string rockHelmDesc = "A rock helmet to protect your big brain.";
std::string rockChestDesc = "The name kind of says it all.";
std::string rockLeggDesc = "Don\'t even ask how you walk in these.";
std::string rockBootsDesc = "Impractical but effective.";
Armor rockHelm("Helmet Made Of Rocks", 10, 10, 8, 20, Helmet, rockHelmDesc);
Armor rockChest("Chestplate Made Of Rocks", 10, 10, 50, 20, Chestplate, rockChestDesc);
Armor rockLegg("Leggings Made Of Rocks", 15, 10, 8, 20, Leggings, rockLeggDesc);
Armor rockBoots("Shoes Made Of Rocks", 20, 5, 10, 20, Boots, rockBootsDesc);

std::string goldHelmDesc = "A nice and shiny helmet to protect your head. Too bad its stats are garbage.";
std::string goldChestDesc = "A weak chestplate made of gold. Rare and valuable.";
std::string goldLeggDesc = "May not be strong but it looks nice!";
std::string goldBootsDesc = "What it lacks in defense it makes up in drip.";
Armor goldHelm("Gold Armor", 15, 5, 5, 120, Helmet, goldHelmDesc);
Armor goldChest("Gold Armor", 15, 5, 5, 150, Chestplate, goldChestDesc);
Armor goldLegg("Gold Armor", 15, 5, 5, 100, Leggings, goldLeggDesc);
Armor goldBoots("Gold Armor", 15, 5, 5, 120, Boots, goldBootsDesc);

std::string vestDesc = "A tough and durable bulletproof vest.";
Armor toughVest("Tough Vest", 75, 15, 10, 30, Chestplate, vestDesc);

std::string baboomArmorDesc = "Rare armor that gives you the fighting spirit of a baboon.";
std::string armyVestDesc = "An bulletproof vest that has the Marines emblem on it. Increases manliness.";
std::string mBobArmorDesc = "With this armor, you will be coming for Monkey Bob. MAY OBAMA BE EVER IN YOUR FAVOR.";
Armor baboonArmor("Baboon Armor", 50, 5, 5, 25, 50, Chestplate, baboomArmorDesc);
Armor armyVest("Marine Vest", 75, 10, 10, 5, 40, Chestplate, armyVestDesc);
Armor monkeyBobArmor("Monkey Bob's Armor", 999999, 25, 25, 35, 350, Chestplate, mBobArmorDesc);
