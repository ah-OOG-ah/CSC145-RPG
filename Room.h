#pragma once

#include <string>
#include <cstdint>

class Room
{
    protected:
    std::string roomName;
    std::string description;
    std::string mapDisplay = " ";

    public:
    std::string GetName();
    std::string GetDesc();
    std::string GetMapDisplay();

    virtual void GenerateRoom(int64_t ran1, int64_t ran2, int64_t ran3, int64_t ran4, int64_t ran5) = 0;
};