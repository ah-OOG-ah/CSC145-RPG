#pragma once

#include <cstdint>
#include <vector>
#include "Room.h"


/**
 * Holds the room layout and is responsible for procedural generation.
 */
class Floor {

  private:
    const int64_t level;
    const int64_t size; // All levels are square, this is the side length
    std::vector<Room> rooms;

    [[nodiscard]] size_t index(int64_t x, int64_t y) const;
};
