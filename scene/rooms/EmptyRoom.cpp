#include "EmptyRoom.h"
#include "game.h"


EmptyRoom::EmptyRoom(std::shared_ptr<Movement> m) : Room("Empty", std::move(m)) {
    switch (getRand() % 4) {
        case 1:
            description = "You enter a blank room with a small lantern hanging form the ceiling in the center";
            break;
        case 2:
            description = "You enter a peaceful room covered in moss. A small fountain is in the center";
            break;
        case 3:
            description = "You enter a room covered in cobwebs. No enemies seem to be near... nor anything alive";
            break;
        default:
            description = "You enter a room with a mop. Not much to look at";
            break;
    }
}