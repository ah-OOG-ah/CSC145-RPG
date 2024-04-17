#pragma once

#include "Enemy.h"
#include "itemtiers.h"

std::string spiderSprite = 
"     \n"  
"     \n"
"/\\O/\\\n"
"     \n"
"     \n";

//Enemy(name,hp,attk,percDef,staticDef,spd, invenSlots, weaponSlots, armorSlots, sprite)
Enemy wideSpider ("WIDE Spider", 30, 10, 10, 5, noItems, noWeapons, noArmor, spiderSprite);
