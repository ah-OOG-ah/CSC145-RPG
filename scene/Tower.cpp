#include "Tower.h"

#include <utility>


Tower::Tower(std::string name) : Scene(std::move(name)) { }

void Tower::run() {

    // Run and enter the floor
    for (int64_t level = 1; level <= 100; ++level) {
        floors.emplace_back(level);
    }
}
