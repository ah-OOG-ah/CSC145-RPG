#include "TreasureRoom.h"
#include "game.h"
#include "scene/Battle.h"


TreasureRoom::TreasureRoom(std::shared_ptr<Movement> m, uint8_t mask, int64_t nice) : Room("Treasure", std::move(m), mask, nice) {
    switch (randUint() % 1) {
        case 0:
            entityName = "The Tree";
            description = "an earthy room with a large tree filling the center";
            dialogueHead = std::make_shared<MenuNode>("Welcome to my grove.");
            auto hostile = dialogueHead->addChild("Strike the tree", dialogueHead);
            dialogueHead->addChild("Hug the tree", dialogueHead)->flag = 1;
            hostile = hostile->addChild("You dare savage my bark!?!", hostile);
            hostile->addChild("Say sorry", hostile);
            hostile->addChild("Strike again", hostile)->flag = -1;
            hostile->addChild("Insult mother", hostile)->flag = -2;
            break;
    }
}

void TreasureRoom::specialAction() {
    auto node = dialogueHead;
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
            std::cout << entityName << " defends his mother\'s honor with a most hateful rage!" << std::endl;
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
            break;
        case 1:
            if (randBool()) {
            } else {
                std::cout << entityName << " grants you a treasure!" << std::endl;
            }
            break;
        default:
            break;
    }
}
