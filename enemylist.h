#pragma once

#include "Enemy.h"
#include "itemtiers.h"
#include <string>
#include "enemyai.h"


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
"HAIL PUTIN\n"
"{(|)..(|)}\n"
"    --    \n";

//Enemy(name,hp,attk,percDef,staticDef,spd, invenSlots, weaponSlots, armorSlots, sprite)
Enemy wideSpider ("WIDE Spider", 20, 10, 1.0, 5, 20, noAttk, noHeal, basicRoids, noWeapons, noArmor, spiderSprite, AttackOnly);
Enemy rockMonster ("Rock Monster", 50, 5, .30, 30, 5, rocksOnly, noHeal, basicRoids, noWeapons, rockSet, rockSprite, DefaultAI);
Enemy baboon("Baboon", 30, 10, .90, 10, 10, basicAttkItems, basicHealItems, allRoids, swordsOnly, noArmor, baboonSprite, MidLevelAI);
//Only difference between two baboons is behavior and sprite
Enemy angryBaboon("Angry Baboon", 40, 10, .90, 10, 10, basicAttkItems, basicHealItems, allRoids, swordsOnly, noArmor, angryBaboonSprite, AttackOnly);
Enemy smallSentry("Mini Sentry", 50, 25, .80, 12, 15, basicAttkItems, betterHealItems, shieldOnly, rareWeapons, chainSet, std::vector<Item*>{&sentryHead}, smallSentrySprite, MidLevelAI);
Enemy sentry("Sentry", 80, 30, .75, 12, 5, betterAttkItems, betterHealItems, shieldOnly, rareWeapons, betterArmor, std::vector<Item*>{&sentryHead}, sentrySprite, HighLevelAI);
Enemy steelSentry("Steel sentry", 100, 30, .70, 12, 5, betterAttkItems, betterHealItems, shieldOnly, rareWeapons, steelSet, std::vector<Item*>{&sentryHead}, steelSentrySprite, HighLevelAI);
Enemy basedBat("Based Bat", 35, 15, 1.0, 7, 30, basicAttkItems, noHeal, basicRoids, basicWeapons, basicArmor, batSprite, DefaultAI);
Enemy veryBasedBat("Very Based Bat", 50, 18, 1.0, 10, 35, basicAttkItems, noHeal, allRoids, basicWeapons, steelSet, batSprite, MidLevelAI);
Enemy tradBasedBat("Based and Trad Bat", 55, 25, 1.0, 12, 35, bombsOnly, noHeal, goodStatusItems, rareWeapons, topTierArmor, tradBatSprite, HighLevelAI);
Enemy mummy("Mummy", 65, 20, 1.0, 10, 12, greatAttkItems, betterHealItems, mummyItems, undeadWeapons, noArmor, std::vector<Item*>{&zombieBlood}, mummySprite, MidLevelAI);
Enemy zombie("Zombie", 65, 20, 1.0, 10, 12, greatAttkItems, basicHealItems, allRoids, undeadWeapons, noArmor, std::vector<Item*>{&zombieBlood}, zombieSprite, MidLevelAI);
Enemy ghoul("Ghoul", 60, 10, .80, 20, 30, betterAttkItems, noHeal, shieldOnly, undeadWeapons, basicArmor, ghoulSprite, MidLevelAI);
Enemy monkeyGhoul("Monkey Ghoul", 65, 25, .82, 15, 15, betterAttkItems, noHeal, shieldOnly, undeadWeapons, basicArmor, monkeyGhoulSprite, MidLevelAI);
Enemy cryptogriph("Cryptogriph", 50, 10, .60, 16, 40, powerfulAttkItems, betterHealItems, sleepingPillsOnly, swordsOnly, steelSet, std::vector<Item*>{&elixir, &goldBoots, &goldChest, &goldSword}, cryptogriphSprite, ItemHappy);

Enemy MonkeyBob("Monkey Bob", 200, 40, .50, 35, 50, powerfulAttkItems, betterHealItems, std::vector<StatusItem>{superRoids}, rareWeapons, topTierArmor, MonkeyBobSprite, HighLevelAI);