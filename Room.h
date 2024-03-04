#pragma once

#include <string>
#include <cstdint>

class Room
{
    protected:
    std::string roomName;
    std::string description;

    public:
    std::string GetName();
    std::string GetDesc();

    virtual void GenerateRoom(int64_t ran1, int64_t ran2, int64_t ran3) = 0;
};