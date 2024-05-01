#include "TreasureRoom.h"
#include "game.h"
#include "scene/Battle.h"


TreasureRoom::TreasureRoom(std::shared_ptr<Movement> m, uint8_t mask, int64_t nice) : Room("Treasure", std::move(m), mask, nice) {
    switch (randUint() % 1) {
        case 0:
            entityName = "The Tree";
            description = "an earthy room with a large tree filling the center";
            dialogueHead = std::make_shared<MenuNode>(entityName + ": Welcome to my grove.");
            auto hostile = dialogueHead->addChild("Strike the tree", dialogueHead);
            dialogueHead->addChild("Hug the tree", dialogueHead)->flag = 1;
            hostile = hostile->addChild(entityName + ": You dare savage my bark!?!", hostile);
            hostile->addChild("Say sorry", hostile);
            hostile->addChild("Strike again", hostile)->flag = -1;
            hostile->addChild("Insult mother", hostile)->flag = -2;
            break;
        case 1:
            entityName = "The Chest";
            description = "an prison-like chamber. A metal chest sits in the center.";
            dialogueHead = std::make_shared<MenuNode>("Hello there");
            auto hostile = dialogueHead->addChild("Open chest", dialogueHead);
            dialogueHead->addChild("Greet chest", dialogueHead);
            hostile = hostile->addChild("Woah! Do not be so hasty!", hostile);
            auto inquire = hostile->addChild("What are you\?", hostile);
            hostile->addChild("Did not mean to cause trouble", hostile);
            hostile->addChild("Open chest", hostile)->flag = -1;
            inquire = inquire("A humble talking chest without a friend in the world. Will you be my friend\?");
            inquire->addChild("Of course!", inquire)->flag = -2;
            inquire->addChild("No!", inquire);
            break;
    }
}

void TreasureRoom::specialAction() {
    auto node = dialogueHead;
    std::cout << node->getData() << std::endl;
    while (!node->isLeaf()) {
        node->generateFuncs(node);
        node->display();
    }

    /**
     * -2 - Always battle
     * -1 - 50/50 hostile v die
     *  0 - nothing
     *  1 - 50/50 nothing v treasure
     */
    switch (node->flag) {
        case -2:
            std::cout << entityName << " lashed at you with a most vicious rage!" << std::endl;
            Battle(entityName, 10).run();
            break;
        case -1:
            if (randBool()) {
                std::cout << entityName << " won't go down without a fight!" << std::endl;
                Battle(entityName, 7).run();
            } else {
                std::cout << "Despite its posturing, " << entityName << " dies in just a few swings." << std::endl;
            }
            break;
        case 0:
            std::cout << entityName << ": \"Leave! Monkey Bob will find you eventually!\"" << std::endl;
            break;
        case 1:
            if (randBool()) {
                std::cout << entityName << " wished you a good day" << std::endl;
            break;
            } else {
                std::cout << entityName << " grants you a treasure!" << std::endl;
            }
            break;
        default:
            break;
    }
}
