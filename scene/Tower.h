#pragma once

#include <vector>
#include "Floor.h"
#include "Scene.h"

/**
 * Represents the Tower as a whole - holds the state of pretty much everything.
 */
class Tower : public Scene {

  private:
    std::vector<Floor> floors;
};
