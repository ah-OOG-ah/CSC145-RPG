#include "TreasureRoom.h"
#include "game.h"


Item* TreasureRoom::GetTreasure() { return treasure; }
Item* TreasureRoom::GetTreasure2() { return treasure2; }

TreasureRoom::TreasureRoom(std::string name) : Room(std::move(name)) {
    switch (getRand() % 4) {
        case 0:
            description = "You enter a blank room with a small lantern hanging form the ceiling in the center";
            break;
        case 1:
            description = "You enter a peaceful room covered in moss. A small fountain is in the center";
            break;
        case 2:
            description = "You enter a room covered in cobwebs. No enemies seem to be near... nor anything alive";
            break;
        default:
            description = "You enter a room with a mop. Not much to look at";
            break;
    }
    //Switch statement for spawn table

    //Switch statement for treasure

    //Switch statement for treasure2
}
