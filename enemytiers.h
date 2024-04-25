#pragma once

#include "enemylist.h"
#include <vector>


namespace ETiers {

    using namespace EList;

    static const std::vector<Enemy*> basicEnemies = {&wideSpider, &wideSpider, &baboon, &basedBat, &baboon, &angryBaboon};
    static const std::vector<Enemy*> sentriesOnly = {&smallSentry, &smallSentry, &sentry, &sentry, &sentry, &steelSentry};
    static const std::vector<Enemy*> monkeysOnly = {&baboon, &baboon, &angryBaboon, &angryBaboon, &monkeyGhoul};
    static const std::vector<Enemy*> undeadOnly = {&zombie, &mummy, &ghoul, &monkeyGhoul, &zombie, &mummy, &ghoul, &monkeyGhoul, &cryptogriph};
    static const std::vector<Enemy*> batsOnly = {&basedBat, &basedBat, &basedBat, &veryBasedBat, &veryBasedBat, &tradBasedBat};
    static const std::vector<Enemy*> harderEnemies = {&veryBasedBat, &tradBasedBat, &sentry, &sentry, &steelSentry, &angryBaboon, &zombie, &ghoul, &cryptogriph};
    static const std::vector<Enemy*> hardEnemies = {&steelSentry, &cryptogriph, &mummy, &zombie};

    std::vector<Enemy*> get(int64_t i) {
        switch (std::min(std::max(0l, i - 1), 6l)) {
            case 0: return basicEnemies;
            case 1: return sentriesOnly;
            case 2: return monkeysOnly;
            case 3: return undeadOnly;
            case 4: return batsOnly;
            case 5: return harderEnemies;
            default: return hardEnemies;
        }
    }
}