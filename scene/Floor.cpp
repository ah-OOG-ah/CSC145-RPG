#include "Floor.h"
#include "scene/rooms/BattleRoom.h"
#include "scene/rooms/SafeRoom.h"
#include "scene/rooms/Movement.h"
#include "game.h"

#include <utility>
#include <iostream>


size_t Floor::index(int64_t x, int64_t y) const { return x + y * size; }

Floor::Floor(std::string name, int64_t level) : Scene(std::move(name)), level(level), size(5) { }

void Floor::run() {
    auto movement = std::make_shared<Movement>();
    auto p = getPlayer();

    // Generate rooms
    // First one is safe
    rooms.push_back(std::make_shared<SafeRoom>(movement, 0b0101));

    // For now, every other room is a battle
    for (int64_t i = 1; i < size * size; ++i) {
        int8_t mask = 0b0;

        // Not on the top edge
        if (i > 4) { mask |= 0b1000; }

        // Not on the bottom edge
        if (i < 20) { mask |= 0b0100; }

        // Not on the left edge
        if (i % 5 != 0) { mask |= 0b0010; }

        // Not on the right edge
        if (i % 5 != 4) { mask |= 0b0001; }

        rooms.push_back(std::make_shared<BattleRoom>(movement, mask));
    }

    // Enter the room
    while (p->x != 4 || p->y != 4) {
        auto room = rooms[index(p->x, p->y)];
        std::cout << room->GetDesc() << std::endl;
        room->display();

        std::cout << "Movement: " << movement->toString() << std::endl;
        if (movement->isX) p->x += movement->incX ? 1 : -1;
        if (movement->isY) p->y += movement->incY ? 1 : -1;
        movement->reset();
        std::cout << "You are at: " << p->x << ", " << p->y << std::endl;
    }

    std::cout << "TODO: implement floor" << std::endl;
}
