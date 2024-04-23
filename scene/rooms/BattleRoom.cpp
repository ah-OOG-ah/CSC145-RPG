#include "BattleRoom.h"

#include <utility>
#include "game.h"


BattleRoom::BattleRoom(std::shared_ptr<Movement> m, uint8_t mask) : Room("Battle", std::move(m), mask) {
    auto rand = randUint() % 4;

    switch (rand) {
        case 0:
            description = "You enter a dark room with a broken chain dangling from the ceiling";
            break;
        case 1:
            description = "You enter a damp room covered in moss. A crumbling heap of stone is in the center";
            break;
        case 2:
            description = "You enter a room covered in cobwebs. Nothing appears.. nothing standing, at least.";
            break;
        default:
            description = "You enter a room with a mop. Not much to look at";
            break;
    }
    //Switch statement for spawn table

    //Switch statement for treasure
}

Item* BattleRoom::GetTreasure() { return treasure; }