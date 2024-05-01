#pragma once

#include "enemylist.h"
#include <vector>


namespace ETiers {

    using namespace EList;

    // Mixed enemy lists
    static const std::vector<std::shared_ptr<Enemy>> basicEnemies { rockMonster, wideSpider, wideSpider, baboon, basedBat, baboon, angryBaboon };
    static const std::vector<std::shared_ptr<Enemy>> harderEnemies { rockMonster, veryBasedBat, tradBasedBat, sentry, sentry, steelSentry, angryBaboon, zombie, ghoul, cryptogriph };
    static const std::vector<std::shared_ptr<Enemy>> hardEnemies { steelSentry, cryptogriph, mummy, zombie };

    // Special sets
    static const std::vector<std::shared_ptr<Enemy>> sentriesOnly { smallSentry, smallSentry, sentry, sentry, sentry, steelSentry };
    static const std::vector<std::shared_ptr<Enemy>> monkeysOnly { baboon, baboon, angryBaboon, angryBaboon, monkeyGhoul };
    static const std::vector<std::shared_ptr<Enemy>> undeadOnly { zombie, mummy, ghoul, monkeyGhoul, zombie, mummy, ghoul, monkeyGhoul, cryptogriph };
    static const std::vector<std::shared_ptr<Enemy>> batsOnly { basedBat, basedBat, basedBat, veryBasedBat, veryBasedBat, tradBasedBat };

    std::vector<std::shared_ptr<Enemy>> get(int64_t i) {
        switch (std::min(std::max(static_cast<int64_t>(0), i - 1), static_cast<int64_t>(6))) {
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