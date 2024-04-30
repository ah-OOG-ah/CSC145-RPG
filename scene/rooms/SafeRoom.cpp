#include "SafeRoom.h"

#include <utility>
#include "game.h"


// TODO: add posters
SafeRoom::SafeRoom(std::shared_ptr<Movement> m, uint8_t mask, int64_t nice) : Room("Safe", std::move(m), mask, nice) {
    switch (randUint() % 8) {
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
            description = "a room with a weathered plank floor. The drops of water falling into a bucket are the only sounds that accompany this empty room";
            break;
        case 4:
            description = "a room with ash and charred trash lying in the center";
            break;
        case 5:
            description = "a forboding room. A monkey face is drawn in the dirt, with a wicked grin";
            break;
        case 6:
            description = "a room that used to be a fine kitchen. Bananas and bloody knives are spread throughout";
            break;
        default:
            description = "a room with a mop. Not much to look at";
            break;
    }
}
