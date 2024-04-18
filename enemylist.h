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

//Enemy(name,hp,attk,percDef,staticDef,spd, invenSlots, weaponSlots, armorSlots, sprite)
Enemy wideSpider ("WIDE Spider", 20, 10, 10, 5, 20, rocksOnly, noWeapons, noArmor, spiderSprite);
Enemy rockMonster ("Rock Monster", 50, 5, 30, 30, 5, noItems, noWeapons, rockSet, spiderSprite);