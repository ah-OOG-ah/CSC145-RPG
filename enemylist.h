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
"(080)\n"
"     \n"
"     \n";

std::string batSprite =
"     \n"
"     \n"
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

//Enemy(name,hp,attk,percDef,staticDef,spd, invenSlots, weaponSlots, armorSlots, sprite)
Enemy wideSpider ("WIDE Spider", 20, 10, 10, 5, 20, rocksOnly, noWeapons, noArmor, spiderSprite);
Enemy rockMonster ("Rock Monster", 50, 5, 30, 30, 5, noItems, noWeapons, rockSet, rockSprite);
Enemy baboon("Baboon", 30, 10, 10, 10, 10, basicItems, swordsOnly, noArmor, baboonSprite);
Enemy smallSentry("Mini Sentry", 50, 25, 12, 12, 15, healItemsOnly, rareWeapons, chainSet, smallSentrySprite);
Enemy sentry("Sentry", 80, 30, 20, 12, 5, healItemsOnly, rareWeapons, betterArmor, sentrySprite);
Enemy steelSentry("Steel sentry", 100, 30, 30, 18, 5, healItemsOnly, rareWeapons, steelSet, steelSentrySprite);
Enemy basedBat("Based Bat", 35, 15, 7, 7, 30, basicItems, basicWeapons, basicArmor, batSprite);
Enemy veryBasedBat("Very Based Bat", 50, 18, 10, 10, 35, basicItems, basicWeapons, steelSet, batSprite);
Enemy tradBasedBat("Based and Trad Bat", 75, 25, 7, 12, 35, basicItems, rareWeapons, topTierArmor, batSprite);