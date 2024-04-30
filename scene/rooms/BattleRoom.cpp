#include "BattleRoom.h"
#include <utility>
#include "game.h"
#include "scene/Battle.h"


BattleRoom::BattleRoom(std::shared_ptr<Movement> m, uint8_t mask, int64_t nice)
    : Room("Battle", std::move(m), mask, nice), b(roomName, nice) {
    auto rand = randUint() % 4;

    switch (rand) {
        case 0:
            description = "a dark room with a broken chain dangling from the ceiling";
            break;
        case 1:
            description = "a damp room covered in moss. A crumbling heap of stone is in the center";
            break;
        case 2:
            description = "a room covered in cobwebs. Nothing appears.. nothing standing, at least.";
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
