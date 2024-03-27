#include <format>
#include <iostream>
#include "Floor.h"

Floor::Floor(uint64_t level) : Scene("Floor " + std::to_string(level)), level(level) {}

void Floor::run() {

    // If the current room doesn't exist, generate
    if (!generated[x][y]) {
        std::cout << "Not implemented yet, sorry!" << std::endl;
        return;
    }
}
