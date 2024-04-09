#include "item.h"
#include "RegularItems.h"
#include "Equipment.h"
//AttackIem(Name, damage, price)
AttackItem rock("Rock", 5, 2);
AttackItem dart("Dart", 8, 5);

//HealItem(Name, healAmnt, price)
HealItem pureWater("Pure Water", 15, 9);
HealItem elixir("Elixir", 40, 25);
HealItem cookie("Cookie", 5, 3);

//Weapon(Name, durability, damage, price)
Weapon sword("Sword", 20, 25, 20);
Weapon spear("Spear", 10, 20, 15);
Weapon hammer("Gorilla Hammer", 30, 50, 45);
Weapon staff("Staff", 10, 10, 8);
Weapon bottle("Broken Bottle", 3, 70, 4);
Weapon goldSword("Gold Sword", 5, 50, 100);
Weapon whip("Orphan Whip", 30, 5, 20);

//Armor(Name, durability, percentageDef, staticDef, price)
Armor steelArmor("Steel Armor", 50, 12, 20, 30);
Armor chainMeal("Chain Armor", 35, 20, 8, 25);
Armor rockArmor("Armor Made Of Rocks", 30, 5, 50, 20);
Armor goldArmor("Gold Armor", 15, 5, 5, 120);
Armor toughVest("Tough Vest", 75, 10, 5, 25);

//Special Armor(Name, durability, percentageDef, staticDef, damageMultiplier, price)
SpeicalArmor baboonArmor("Baboon Armor", 50, 5, 5, 25, 50);
SpecialArmor armyVest("Marine Vest", 50, 10, 10, 5, 40);
SpeicalArmor monkeyBobArmor("Monkey Bob's Armor", 100, 25, 25, 35, 350);
