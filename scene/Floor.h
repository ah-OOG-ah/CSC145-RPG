#pragma once

#include <cstdint>
#include <vector>
#include <memory>
#include "scene/rooms/Room.h"
#include "Scene.h"


/**
 * Holds the room layout and is responsible for procedural generation.
 */
class Floor : public Scene {

  private:
    const int64_t level;
    const int64_t size; // All levels are square, this is the side length
    std::vector<std::shared_ptr<Room>> rooms;

    [[nodiscard]] size_t index(int64_t x, int64_t y) const;

  public:
    Floor(std::string name, int64_t level);

    void run() override;
};
