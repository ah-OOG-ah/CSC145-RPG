#include "item.h"
#include "RegularItems.h"
#include "Equipment.h"
//AttackIem(Name, damage, price, description)
std::string rockDesc = "A simple rock to throw at enemies. Damage: 5";
std::string dartDesc = "Peruvian dart to throw at enemies. Damage: 8";
AttackItem rock("Rock", 5, 2, rockDesc);
AttackItem dart("Dart", 8, 5, dartDesc);

//HealItem(Name, healAmnt, price, description)
std::string waterDesc = "Clear water as pure as Ryan Reynolds. Heals 15 HP";
std::string elixirDesc = "strange liquid with the consistency of medicine but taste of milk. Heals 40 HP";
std::string cookieDesc = "A delicous cookie. Heals 5 HP";
HealItem pureWater("Pure Water", 15, 9, waterDesc);
HealItem elixir("Elixir", 40, 25, elixirDesc);
HealItem cookie("Cookie", 5, 3, cookieDesc);

//Weapon(Name, durability, damageMultiplier, price, description)
std::string swordDesc = "A mighty sword, made of Grecian Iron. Strength: 25";
std::string spearDesc = "Light spear with a hard oak shaft. Strength: 25";
std::string hammerDesc = "A heavy hammer to impound heads with. Strength: 50";
std::string staffDesc = "An old staff. While it has seem better days, it still has use. Strength: 10";
std::string bottleDesc = "A broken bottle of beer. Great for dealing damage but easily broken. Strength: 70";
std::string goldSwordDesc = "A heavy sword made of solid gold. Not very durable but highly prized by merchants. Strength: 50";
std::string whipDesc = "a flexible and durable whip, handy to beat orphans. Strength: 5";
Weapon sword("Sword", 20, 25, 20, swordDesc);
Weapon spear("Spear", 10, 20, 15, spearDesc);
Weapon hammer("Gorilla Hammer", 30, 50, 45, hammerDesc);
Weapon staff("Staff", 10, 10, 8, staffDesc);
Weapon bottle("Broken Bottle", 3, 70, 4, bottleDesc);
Weapon goldSword("Gold Sword", 5, 50, 100, goldSwordDesc);
Weapon whip("Orphan Whip", 40, 5, 20, whipDesc);

//Armor(Name, durability, percentageDef, staticDef, price, description)
std::string steelArmorDesc = "Durable armor made of pure iron. PD: 12 Percent, SD: 20";
std::string chainMealDesc = "Armor made of chain links. Has low Static Defense but high Percentage Defense. PD: 20 Percent, SD: 8";
std::string rockArmorDesc = "The name kind of says it all. PD: 5 Percent, SD: 30";
std::string goldArmorDesc = "Weak armor made of gold. Rare and valuable. PD: 5 Percent, SD: 5";
std::string vestDesc = "A tough and durable bulletproof vest. PD: 10 Percent, SD: 5";
Armor steelArmor("Steel Armor", 50, 12, 20, 30, steelArmorDesc);
Armor chainMeal("Chain Armor", 35, 20, 8, 25, chainMealDesc);
Armor rockArmor("Armor Made Of Rocks", 5, 30, 50, 20, rockArmorDesc);
Armor goldArmor("Gold Armor", 15, 5, 5, 120, goldArmorDesc);
Armor toughVest("Tough Vest", 75, 10, 5, 25, vestDesc);

//Special Armor(Name, durability, percentageDef, staticDef, damageMultiplier, price, description)
std::string baboomArmorDesc = "Rare armor that gives you the fighting spirit of a baboon. PD: 5, SD: 5, Strength: 25";
std::string armyVestDesc = "An bulletproof vest that has the Marines emblem on it. Increases manliness. PD: 10, SD: 10, Strength: 5";
std::string mBobArmorDesc = "With this armor, you will be coming for Monkey Bob. MAY OBAMA BE EVER IN YOUR FAVOR. PD: 25, SD: 25, Strength: 35";
SpecialArmor baboonArmor("Baboon Armor", 50, 5, 5, 25, 50);
SpecialArmor armyVest("Marine Vest", 75, 10, 10, 5, 40);
SpecialArmor monkeyBobArmor("Monkey Bob's Armor", 999, 25, 25, 35, 350);
