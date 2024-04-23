#include "SafeRoom.h"

#include <utility>
#include "game.h"


SafeRoom::SafeRoom(std::shared_ptr<Movement> m, uint8_t mask) : Room("Safe", std::move(m), mask) {
    switch (randUint() % 4) {
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
}
