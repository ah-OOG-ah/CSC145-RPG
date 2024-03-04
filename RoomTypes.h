#pragma once

#include <string>
#include "item.h"
#include "Room.h"
#include <cstdint>

class SafeRoom : public Room
{
    public:
    void GenerateRoom(int64_t ran1, int64_t ran2, int64_t ran3) override;
};

