#pragma once

#include "enemylist.h"
#include <vector>

std::vector<Enemy*> basicEnemies = {&wideSpider, &wideSpider, &baboon, &basedBat, &baboon, &angryBaboon };
std::vector<Enemy*> sentriesOnly = {&smallSentry, &smallSentry, &sentry, &sentry, &sentry, &steelSentry };
std::vector<Enemy*> monkeysOnly = {&baboon, &baboon, &angryBaboon, &angryBaboon, &monkeyGhoul };
std::vector<Enemy*> undeadOnly = { &zombie, &mummy, &ghoul, &monkeyGhoul, &zombie, &mummy, &ghoul, &monkeyGhoul, &cryptogriph };
std::vector<Enemy*> batsOnly = {&basedBat, &basedBat, &basedBat, &veryBasedBat, &veryBasedBat, &tradBasedBat }; 
std::vector<Enemy*> harderEnemies = {&veryBasedBat, &tradBasedBat, &sentry, &sentry, &steelSentry, &angryBaboon, &zombie, &ghoul, &cryptogriph };
std::vector<Enemy*> hardEnemies = {&steelSentry, &cryptogriph, &mummy, &zombie };