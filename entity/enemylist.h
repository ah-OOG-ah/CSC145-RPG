#pragma once

#include "Enemy.h"
#include "itemtiers.h"
#include <string>
#include "EnemyAI.h"
#include "Util.h"


namespace EList {

    std::array<std::string, 5> spiderSprite {
        "     ",
        "     ",
        "/\\O/\\",
        "     ",
        "     "
    };

    std::array<std::string, 5> rockSprite {
        "     ",
        " --- ",
        "/  \\",
        "\\   /",
        " --- "
    };

    std::array<std::string, 5> baboonSprite {
        "     ",
        "     ",
        " 0..0",
        "  -- ",
        "     "
    };

    std::array<std::string, 5> angryBaboonSprite {
        "     ",
        " \\  /",
        " O..O",
        "  ~~ ",
        "     "
    };

    std::array<std::string, 5> batSprite {
        "     ",
        "     ",
        " \\o/ ",
        "     ",
        "     "
    };

    std::array<std::string, 5> tradBatSprite {
        "     ",
        "  +  ",
        " \\o/ ",
        "     ",
        "     "
    };

    std::array<std::string, 5> sentrySprite {
        " (0) ",
        "-----",
        "|   |",
        "|   |",
        "() ()"
    };

    std::array<std::string, 5> steelSentrySprite {
        " [8] ",
        "-----",
        "|###|",
        "|###|",
        "() ()"
    };

    std::array<std::string, 5> smallSentrySprite {
        "     ",
        "  o  ",
        " --- ",
        " | | ",
        " O O "
    };

    std::array<std::string, 5> mummySprite {
        "     ",
        "  O  ",
        " /#\\ ",
        "  #  ",
        " # # "
    };

    std::array<std::string, 5> zombieSprite {
        "     ",
        "     ",
        "  O  ",
        " /%\\ ",
        " / \\ "
    };

    std::array<std::string, 5> ghoulSprite {
        "     ",
        "(* *)",
        "  *  ",
        "  *  ",
        " *** "
    };

    std::array<std::string, 5> monkeyGhoulSprite {
        "     ",
        "*. .*",
        " ___ ",
        "  *  ",
        " *** "
    };

    std::array<std::string, 5> cryptogriphSprite {
        " ^ ^ ",
        " ^ ^ ",
        "{***}",
        " ### ",
        "@ @ @"
    };

    std::array<std::string, 5> MonkeyBobSprite = {
        "HAIL PUTIN",
        "{(|)..(|)}",
        "    --    ",
        "          ",
        "          "
    };

    using namespace ITiers;

    static const auto noLoot = std::vector<std::shared_ptr<Item>>();
    static const auto sentryLoot = std::vector<std::shared_ptr<Item>> { sentryHead };
    static const auto zombieLoot = std::vector<std::shared_ptr<Item>> { zombieBlood };
    static const auto cryptoLoot = std::vector<std::shared_ptr<Item>> { elixir, goldBoots, goldChest, goldSword };

    static const auto noWeapon = Util<Weapon>::drawFactory({});

    static const auto wideSpider = std::make_shared<Enemy>("WIDE Spider", 20, 10, 1.0, 5, 20, spiderSprite, noLoot, UtilI::drawI({ basicRoids }, 1));
    static const auto rockMonster = std::make_shared<Enemy>("Rock Monster", 50, 5, .30, 30, 5, rockSprite, noLoot, UtilI::drawI({ rocksOnly, basicRoids }, 2), noWeapon, [](){ return rockSet; }, ITEM_HAPPY);
    static const auto baboon = std::make_shared<Enemy>("Baboon", 30, 10, .90, 10, 10, baboonSprite, noLoot, UtilI::drawI({basicAttkItems, basicHealItems, allRoids}, 3), Util<Weapon>::drawFactory(basicWeapons));
    //Only difference between two baboons is behavior and sprite
    static const auto angryBaboon = std::make_shared<Enemy>("Angry Baboon", 40, 10, .90, 10, 10, angryBaboonSprite, noLoot, UtilI::drawI({basicAttkItems, basicHealItems, allRoids}, 3), Util<Weapon>::drawFactory(basicWeapons));
    static const auto smallSentry = std::make_shared<Enemy>("Mini Sentry", 50, 25, .80, 12, 15, smallSentrySprite, sentryLoot, UtilI::drawI({basicAttkItems, betterHealItems, shieldOnly}, 3), Util<Weapon>::drawFactory(rareWeapons), [](){ return chainSet; });
    static const auto sentry = std::make_shared<Enemy>("Sentry", 80, 30, .75, 12, 5, sentrySprite, sentryLoot, UtilI::drawI({betterAttkItems, betterHealItems, shieldOnly}, 3), Util<Weapon>::drawFactory(rareWeapons), UtilI::drawAFactory({ betterArmor }));
    static const auto steelSentry = std::make_shared<Enemy>("Steel sentry", 100, 30, .70, 12, 5, steelSentrySprite, sentryLoot, UtilI::drawI({betterAttkItems, betterHealItems, shieldOnly}, 3), Util<Weapon>::drawFactory(rareWeapons), [](){ return steelSet; });
    static const auto basedBat = std::make_shared<Enemy>("Based Bat", 35, 15, 1.0, 7, 30, batSprite, noLoot, UtilI::drawI({basicAttkItems, noHeal, basicRoids}, 3), Util<Weapon>::drawFactory(basicWeapons), UtilI::drawAFactory(basicArmor));
    static const auto veryBasedBat = std::make_shared<Enemy>("Very Based Bat", 50, 18, 1.0, 10, 35, batSprite, noLoot, UtilI::drawI({basicAttkItems, noHeal, allRoids}, 3), Util<Weapon>::drawFactory(basicWeapons), [](){ return steelSet; });
    static const auto tradBasedBat = std::make_shared<Enemy>("Based and Trad Bat", 55, 25, 1.0, 12, 35, tradBatSprite, noLoot, UtilI::drawI({bombsOnly, noHeal, goodStatusItems}, 3), Util<Weapon>::drawFactory(rareWeapons), UtilI::drawAFactory(topTierArmor));
    static const auto mummy = std::make_shared<Enemy>("Mummy", 65, 20, 1.0, 10, 12, mummySprite, zombieLoot, UtilI::drawI({greatAttkItems, betterHealItems, mummyItems}, 3), Util<Weapon>::drawFactory(undeadWeapons), [](){ return noArmor; });
    static const auto zombie = std::make_shared<Enemy>("Zombie", 65, 20, 1.0, 10, 12, zombieSprite, zombieLoot, UtilI::drawI({greatAttkItems, basicHealItems, allRoids}, 3), Util<Weapon>::drawFactory(undeadWeapons), [](){ return noArmor; });
    static const auto ghoul = std::make_shared<Enemy>("Ghoul", 60, 10, .80, 20, 30, ghoulSprite, noLoot, UtilI::drawI({betterAttkItems, noHeal, shieldOnly}, 3), Util<Weapon>::drawFactory(undeadWeapons), UtilI::drawAFactory(basicArmor));
    static const auto monkeyGhoul = std::make_shared<Enemy>("Monkey Ghoul", 65, 25, .82, 15, 15, monkeyGhoulSprite, noLoot, UtilI::drawI({betterAttkItems, noHeal, shieldOnly}, 3), Util<Weapon>::drawFactory(undeadWeapons), UtilI::drawAFactory(basicArmor));
    static const auto cryptogriph = std::make_shared<Enemy>("Cryptogriph", 50, 10, .60, 16, 40, cryptogriphSprite, cryptoLoot, UtilI::drawI({powerfulAttkItems, betterHealItems, sleepingPillsOnly}, 3), Util<Weapon>::drawFactory(swordsOnly), [](){ return steelSet; });

    static const auto MonkeyBob = std::make_shared<Enemy>("Monkey Bob", 200, 40, .50, 35, 50, MonkeyBobSprite, noLoot, UtilI::drawI({powerfulAttkItems, betterHealItems, {superRoids}}, 10), Util<Weapon>::drawFactory(rareWeapons), UtilI::drawAFactory(topTierArmor));
}