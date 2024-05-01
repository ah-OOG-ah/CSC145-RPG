#include "TreasureRoom.h"
#include "game.h"


Item* TreasureRoom::GetTreasure() { return treasure; }
Item* TreasureRoom::GetTreasure2() { return treasure2; }

TreasureRoom::TreasureRoom(std::shared_ptr<Movement> m, uint8_t mask, int64_t nice) : Room("Treasure", std::move(m), mask, nice) {
    switch (randUint() % 7) {
        case 0:
            description = "a blank room with a small lantern hanging form the ceiling in the center";
            break;
        case 1:
            description = "a peaceful room covered in moss. A small fountain is in the center";
            break;
        case 2:
            description = "a room covered in cobwebs. No enemies seem to be near... nor anything alive";
            break;
        case 3:
            description = "a room that smells of fresh pine. A rickedy wooden chest lies in the corner, covered in webs";
            break;
        case 4:
            description = "a cold room with a metal chest. A broken padlock with a monkey face is lying next to it";
            break;
        case 5:
            description = "a room with strange gems all around. What could they be here for\?";
            break;
        default:
            description = "a mundane room with a mop. Not much to look at";
            break;
    }
    //Switch statement for spawn table

    //Switch statement for treasure

    //Switch statement for treasure2
}
