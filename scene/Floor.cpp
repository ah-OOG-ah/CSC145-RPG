#include "Floor.h"

#include <utility>
#include <iostream>

size_t Floor::index(int64_t x, int64_t y) const { return x + y * size; }

Floor::Floor(std::string name, int64_t level) : Scene(std::move(name)), level(level), size(5) { }

void Floor::run() {

    // Generate rooms
    // For now, every room is a battle
    std::cout << "TODO: implement floor" << std::endl;
}
