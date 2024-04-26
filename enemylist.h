#pragma once

#include "Enemy.h"
#include "itemtiers.h"
#include <string>
#include "enemyai.h"
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

    //Enemy(name, i64 hp, i64 attk, f64 percDef, i64 staticDef, i64 spd, inv, weapon, armor, sprite, std::function<void(Enemy*, EquippedEntity*)> behavior)
    Enemy wideSpider("WIDE Spider", 20, 10, 1.0, 5, 20, UtilI::drawI({ basicRoids }, 1), nothing, noArmor, spiderSprite, {}, EAI::AttackOnly);
    Enemy rockMonster("Rock Monster", 50, 5, .30, 30, 5, UtilI::drawI({ rocksOnly, basicRoids }, 2), nothing, rockSet, rockSprite, {}, EAI::DefaultAI);
    Enemy baboon("Baboon", 30, 10, .90, 10, 10, UtilI::drawI({basicAttkItems, basicHealItems, allRoids}, 3), Util<Weapon>::draw(basicWeapons), noArmor, baboonSprite, {}, EAI::MidLevelAI);
    //Only difference between two baboons is behavior and sprite
    Enemy angryBaboon("Angry Baboon", 40, 10, .90, 10, 10, UtilI::drawI({basicAttkItems, basicHealItems, allRoids}, 3), Util<Weapon>::draw(basicWeapons), noArmor, angryBaboonSprite, {}, EAI::AttackOnly);
    Enemy smallSentry("Mini Sentry", 50, 25, .80, 12, 15, UtilI::drawI({basicAttkItems, betterHealItems, shieldOnly}, 3), Util<Weapon>::draw(rareWeapons), chainSet, smallSentrySprite, { sentryHead }, EAI::MidLevelAI);
    Enemy sentry("Sentry", 80, 30, .75, 12, 5, UtilI::drawI({betterAttkItems, betterHealItems, shieldOnly}, 3), Util<Weapon>::draw(rareWeapons), UtilI::drawA(betterArmor), sentrySprite, { sentryHead }, EAI::HighLevelAI);
    Enemy steelSentry("Steel sentry", 100, 30, .70, 12, 5, UtilI::drawI({betterAttkItems, betterHealItems, shieldOnly}, 3), Util<Weapon>::draw(rareWeapons), steelSet, steelSentrySprite, { sentryHead }, EAI::HighLevelAI);
    Enemy basedBat("Based Bat", 35, 15, 1.0, 7, 30, UtilI::drawI({basicAttkItems, noHeal, basicRoids}, 3), Util<Weapon>::draw(basicWeapons), UtilI::drawA(basicArmor), batSprite, {}, EAI::DefaultAI);
    Enemy veryBasedBat("Very Based Bat", 50, 18, 1.0, 10, 35, UtilI::drawI({basicAttkItems, noHeal, allRoids}, 3), Util<Weapon>::draw(basicWeapons), steelSet, batSprite, {}, EAI::MidLevelAI);
    Enemy tradBasedBat("Based and Trad Bat", 55, 25, 1.0, 12, 35, UtilI::drawI({bombsOnly, noHeal, goodStatusItems}, 3), Util<Weapon>::draw(rareWeapons), UtilI::drawA(topTierArmor), tradBatSprite, {}, EAI::HighLevelAI);
    Enemy mummy("Mummy", 65, 20, 1.0, 10, 12, UtilI::drawI({greatAttkItems, betterHealItems, mummyItems}, 3), Util<Weapon>::draw(undeadWeapons), noArmor, mummySprite, { zombieBlood }, EAI::MidLevelAI);
    Enemy zombie("Zombie", 65, 20, 1.0, 10, 12, UtilI::drawI({greatAttkItems, basicHealItems, allRoids}, 3), Util<Weapon>::draw(undeadWeapons), noArmor, zombieSprite, { zombieBlood }, EAI::MidLevelAI);
    Enemy ghoul("Ghoul", 60, 10, .80, 20, 30, UtilI::drawI({betterAttkItems, noHeal, shieldOnly}, 3), Util<Weapon>::draw(undeadWeapons), UtilI::drawA(basicArmor), ghoulSprite, {}, EAI::MidLevelAI);
    Enemy monkeyGhoul("Monkey Ghoul", 65, 25, .82, 15, 15, UtilI::drawI({betterAttkItems, noHeal, shieldOnly}, 3), Util<Weapon>::draw(undeadWeapons), UtilI::drawA(basicArmor), monkeyGhoulSprite, {}, EAI::MidLevelAI);
    Enemy cryptogriph("Cryptogriph", 50, 10, .60, 16, 40, UtilI::drawI({powerfulAttkItems, betterHealItems, sleepingPillsOnly}, 3), Util<Weapon>::draw(swordsOnly), steelSet, cryptogriphSprite, { elixir, goldBoots, goldChest, goldSword }, EAI::ItemHappy);

    Enemy MonkeyBob("Monkey Bob", 200, 40, .50, 35, 50, UtilI::drawI({powerfulAttkItems, betterHealItems, {superRoids}}, 10), Util<Weapon>::draw(rareWeapons), UtilI::drawA(topTierArmor), MonkeyBobSprite, {}, EAI::HighLevelAI);
}