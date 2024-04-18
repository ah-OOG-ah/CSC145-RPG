#pragma once

#include "Enemy.h"
#include "itemtiers.h"
#include <string>

std::string spiderSprite = 
"     \n"  
"     \n"
"/\\O/\\\n"
"     \n"
"     \n";

std::string rockSprite =
"     \n"
" --- \n"
"/  \\\n"
"\\   /\n"
" --- \n";

std::string baboonSprite = 
"     \n"
"     \n"
" 0..0\n"
"  -- \n"
"     \n";

std::string angryBaboonSprite = 
"     \n"
" \\  /\n"
" O..O\n"
"  ~~ \n"
"     \n";

std::string batSprite =
"     \n"
"     \n"
" \\o/ \n"
"     \n"
"     \n";

std::string tradBatSprite =
"     \n"
"  +  \n"
" \\o/ \n"
"     \n"
"     \n";

std::string sentrySprite =
" (0) \n"
"-----\n"
"|   |\n"
"|   |\n"
"() ()\n";

std::string steelSentrySprite =
" [8] \n"
"-----\n"
"|###|\n"
"|###|\n"
"() ()\n";

std::string smallSentrySprite =
"     \n"
"  o  \n"
" --- \n"
" | | \n"
" O O \n";

std::string mummySprite =
"     \n"
"  O  \n"
" /#\\ \n"
"  #  \n"
" # # \n";

std::string zombieSprite =
"     \n"
"     \n"
"  O  \n"
" /%\\ \n"
" / \\ \n";

std::string ghoulSprite = 
"     \n"
"(* *)\n"
"  *  \n"
"  *  \n"
" *** \n";

std::string monkeyGhoulSprite = 
"     \n"
"*. .*\n"
" ___ \n"
"  *  \n"
" *** \n";

std::string cryptogriphSprite = 
" ^ ^ \n"
" ^ ^ \n"
"{***}\n"
" ### \n"
"@ @ @\n";

std::string MonkeyBobSprite =
"HAIL OBAMA\n"
"{(|)..(|)}\n"
"    --    \n";

//Enemy(name,hp,attk,percDef,staticDef,spd, invenSlots, weaponSlots, armorSlots, sprite)
Enemy wideSpider ("WIDE Spider", 20, 10, 10, 5, 20, rocksOnly, noWeapons, noArmor, spiderSprite);
Enemy rockMonster ("Rock Monster", 50, 5, 30, 30, 5, noItems, noWeapons, rockSet, rockSprite);
Enemy baboon("Baboon", 30, 10, 10, 10, 10, basicItems, swordsOnly, noArmor, baboonSprite);
//Only difference between two baboons is behavior and sprite
Enemy angryBaboon("Angry Baboon", 30, 10, 10, 10, 10, basicItems, swordsOnly, noArmor, angryBaboonSprite);
Enemy smallSentry("Mini Sentry", 50, 25, 12, 12, 15, sentryItems, rareWeapons, chainSet, std::vector<Item*>{&sentryHead}, smallSentrySprite);
Enemy sentry("Sentry", 80, 30, 20, 12, 5, sentryItems, rareWeapons, betterArmor, std::vector<Item*>{&sentryHead}, sentrySprite);
Enemy steelSentry("Steel sentry", 100, 30, 30, 12, 5, sentryItems, rareWeapons, steelSet, std::vector<Item*>{&sentryHead}, steelSentrySprite);
Enemy basedBat("Based Bat", 35, 15, 7, 7, 30, basicItems, basicWeapons, basicArmor, batSprite);
Enemy veryBasedBat("Very Based Bat", 50, 18, 10, 10, 35, basicItems, basicWeapons, steelSet, batSprite);
Enemy tradBasedBat("Based and Trad Bat", 55, 25, 7, 12, 35, bombsOnly, rareWeapons, topTierArmor, tradBatSprite);
Enemy mummy("Mummy", 65, 20, 10, 10, 12, mummyItems, undeadWeapons, noArmor, std::vector<Item*>{&amulet, &zombieBlood}, mummySprite);
Enemy zombie("Zombie", 65, 20, 10, 10, 12, betterItems, undeadWeapons, noArmor, std::vector<Item*>{&zombieBlood}, zombieSprite);
Enemy ghoul("Ghoul", 60, 10, 20, 20, 30, betterItems, undeadWeapons, basicArmor, ghoulSprite);
Enemy monkeyGhoul("Monkey Ghoul", 65, 25, 15, 15, 15, betterItems, undeadWeapons, basicArmor, monkeyGhoulSprite);
Enemy cryptogriph("Cryptogriph", 50, 10, 24, 16, 40, bombsOnly, swordsOnly, steelSet, std::vector<Item*>{&elixir, &goldBoots, &goldChest, &goldSword}, cryptogriphSprite);

Enemy MonkeyBob("Monkey Bob", 200, 40, 35, 35, 50, gorillaBombOnly, rareWeapons, topTierArmor, MonkeyBobSprite);