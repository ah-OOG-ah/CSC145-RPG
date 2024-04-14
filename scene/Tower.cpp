#include "Tower.h"

#include <utility>
#include <iostream>


Tower::Tower(std::string name) : Scene(std::move(name)) { }

void Tower::run() {

    // Run and enter the floor
    for (int64_t level = 1; level <= 100; ++level) {
        floors.emplace_back("Floor " + std::to_string(level), level);

        std::cout << "You enter Floor " << level << std::endl;
        floors[level - 1].run();
    }
}
