#pragma once

#include <string>

class Room
{
    protected:
    std::string roomName;
    std::string description;

    public:
    std::string GetName();
    std::string GetDesc();

    virtual void GenerateRoom() = 0;
};