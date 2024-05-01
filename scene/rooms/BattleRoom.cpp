#include "BattleRoom.h"
#include <utility>
#include "game.h"
#include "scene/Battle.h"


BattleRoom::BattleRoom(std::shared_ptr<Movement> m, uint8_t mask, int64_t nice)
    : Room("Battle", std::move(m), mask, nice), b(roomName, nice) {
    auto rand = randUint() % 8;

    switch (rand) {
        case 0:
            description = " a dark room with a broken chain dangling from the ceiling";
            break;
        case 1:
            description = "a damp room covered in moss. A crumbling heap of stone is in the center";
            break;
        case 2:
            description = "a room covered in cobwebs. Nothing appears.. nothing standing, at least.";
            break;
        case 3:
            description = "a room with a plank floor. Large holes are scattered throughout the ground";
            break;
        case 4:
            description = "a room with a recently put out campfire in the center";
            break;
        case 5:
            description = "a room. The words \"MONKEY BOB IS COMING FOR YOU\" are carved into the wall";
            break;
        case 6:
            description = "a room with ivory elephants lining up each wall. Monkey statues with spears flank are to their left and right";
            break;
        case 7:
            description = "a room. Just a simple room. What\? Did you want a description\?";
            break;
        default:
            description = "a room with a mop. Not much to look at";
            break;
    }

    //Switch statement for treasure
}

Item* BattleRoom::GetTreasure() { return treasure; }

void BattleRoom::specialAction() {
    b.run();
}
