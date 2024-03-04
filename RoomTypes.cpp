#include "RoomTypes.h"
#include <string>
#include "item.h"
#include "Room.h"
#include <cstdint>

void SafeRoom::GenerateRoom(int64_t ran1, int64_t ran2, int64_t ran3)
{
    switch (ran1)
    {
    case 1:
        description = "You enter a blank room with a small lantern hanging form the ceiling in the center";
        break;
    case 2:
        description = "You enter a peaceful room covered in moss. A small fountain is in the center";
    case 3:
        description = "You enter a room covered in cobwebs. No enemies seem to be near... nor anything alive";
    default:
        description = "You enter a room with a mop. Not much to look at";
        break;
    }
}