#include <string>
#include "Room.h"

std::string Room::GetName() { return roomName; }

std::string Room::GetDesc() { return description; }

std::string Room::GetMapDisplay() 
{ 
    if(isExplored == false)
    {
        return "\?";
    }
    else{
    return mapDisplay; }
}