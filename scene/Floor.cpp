#include "Floor.h"
#include "scene/rooms/BattleRoom.h"
#include "scene/rooms/SafeRoom.h"
#include "scene/rooms/Movement.h"

#include <utility>
#include <iostream>


size_t Floor::index(int64_t x, int64_t y) const { return x + y * size; }

Floor::Floor(std::string name, int64_t level) : Scene(std::move(name)), level(level), size(5) { }

void Floor::run() {
    auto movement = std::make_shared<Movement>();

    // Generate rooms
    // First one is safe
    rooms.push_back(SafeRoom(movement));

    // For now, every room is a battle
    for (int64_t i = 1; i < size * size; ++i) {
        rooms.push_back(BattleRoom(movement));
    }

    // Enter the first room
    rooms[0]

    std::cout << "TODO: implement floor" << std::endl;
}
