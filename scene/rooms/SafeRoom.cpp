#include "SafeRoom.h"

#include <utility>
#include "game.h"


// TODO: add posters
SafeRoom::SafeRoom(std::shared_ptr<Movement> m, uint8_t mask, int64_t nice) : Room("Safe", std::move(m), mask, nice) {
    switch (randUint() % 4) {
        case 0:
            description = "a blank room with a small lantern hanging form the ceiling in the center";
            break;
        case 1:
            description = "a peaceful room covered in moss. A small fountain is in the center";
            break;
        case 2:
            description = "a room covered in cobwebs. No enemies seem to be near... nor anything alive";
            break;
        default:
            description = "aa room with a mop. Not much to look at";
            break;
    }
}
