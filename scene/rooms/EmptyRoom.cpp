#include "EmptyRoom.h"
#include "game.h"


EmptyRoom::EmptyRoom(std::shared_ptr<Movement> m, uint8_t mask, int64_t nice) : Room("Empty", std::move(m), mask, nice) {
    switch (randUint() % 4) {
        case 1:
            description = "a blank room with a small lantern hanging form the ceiling in the center";
            break;
        case 2:
            description = "a peaceful room covered in moss. A small fountain is in the center";
            break;
        case 3:
            description = "a room covered in cobwebs. No enemies seem to be near... nor anything alive";
            break;
        default:
            description = "a room with a mop. Not much to look at";
            break;
    }
}