#pragma once

#include <cstdint>
#include "Room.h"
#include "Scene.h"

class Floor : public Scene {

  private:
    const uint64_t level;
    const Room* rooms[5][5] = {};
    const bool generated[5][5] = {}; // defaults to false

    size_t x = 2;
    size_t y = 2;

  public:
    explicit Floor(uint64_t level);

    void run() override;
};
