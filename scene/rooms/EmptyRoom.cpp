#include "EmptyRoom.h"
#include "game.h"


EmptyRoom::EmptyRoom(std::shared_ptr<Movement> m, uint8_t mask, int64_t nice) : Room("Empty", std::move(m), mask, nice) {
    switch (randUint() % 7) {
        case 1:
            description = "a blank room with a small lantern hanging form the ceiling in the center";
            break;
        case 2:
            description = "a peaceful room covered in moss. A small fountain is in the center";
            break;
        case 3:
            description = "a room covered in cobwebs. No enemies seem to be near... nor anything alive";
            break;
        case 4:
            description = "a room. A voice behind seems to whisper \"Monkey Bob is coming for you\"";
            break;
        case 5:
            description = "a long empty hallway. You think you see a monkey\'s eye stare at you at the end of the hallway";
            break;
        case 6:
            description = "a room with paintings lining the walls. Some seem to be from haunting folktales while others are some are monkeys with bloodshot eyes";
            break;
        case 7:
            description = "a room with only a record player. The song playing sounds like a sick 2000\'s rap song sung by a monkey";
            break;
        default:
            description = "a room with a mop. Not much to look at";
            break;
    }
}