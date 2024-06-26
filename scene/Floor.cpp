#include "Floor.h"
#include "scene/rooms/BattleRoom.h"
#include "scene/rooms/SafeRoom.h"
#include "scene/rooms/Movement.h"
#include "game.h"
#include "scene/rooms/TreasureRoom.h"
#include "scene/rooms/ShopRoom.h"
#include "scene/rooms/EmptyRoom.h"

#include <utility>
#include <iostream>


size_t Floor::index(int64_t x, int64_t y) const { return x + y * size; }

Floor::Floor(std::string name, uint64_t level) : Scene(std::move(name)), level(level), size(5) { }

void Floor::run() {
    auto movement = std::make_shared<Movement>();
    auto p = getPlayer();

    // Generate rooms
    // First one is safe
    //rooms.push_back(std::make_shared<SafeRoom>(movement, 0b0101, level));
    // sike TODO: revert this
    rooms.push_back(std::make_shared<SafeRoom>(movement, 0b0101, level));
    rooms.push_back(std::make_shared<ShopRoom>(movement, 0b0101, level));
    rooms.push_back(std::make_shared<EmptyRoom>(movement, 0b0101, level));
    rooms.push_back(std::make_shared<TreasureRoom>(movement, 0b0101, level));
    rooms.push_back(std::make_shared<BattleRoom>(movement, 0b0101, level));
    rooms.push_back(std::make_shared<BattleRoom>(movement, 0b0101, 20));

    // For now, every other room is a battle
    for (int64_t i = rooms.size(); i < size * size; ++i) {
        int8_t mask = 0b0;

        // Not on the top edge
        if (i > 4) { mask |= 0b1000; }

        // Not on the bottom edge
        if (i < 20) { mask |= 0b0100; }

        // Not on the left edge
        if (i % 5 != 0) { mask |= 0b0010; }

        // Not on the right edge
        if (i % 5 != 4) { mask |= 0b0001; }

        // Now pick the room
        // We use a "niceness" value ranging from 1 to 10 - at 1, there's a roughly even mix of battle/empty (hostile) and
        // treasure/shop (friendly). At 10, there are NO friendly rooms.
        auto nice = std::min(std::max(static_cast<uint64_t>(1), level), static_cast<uint64_t>(10));
        bool friendly = randUint() % 20 > nice + 10;
        if (friendly) {
            if (randBool()) {
                rooms.push_back(std::make_shared<TreasureRoom>(movement, mask, nice));
            } else {
                rooms.push_back(std::make_shared<ShopRoom>(movement, mask, nice));
            }
        } else {
            if (randBool()) {
                rooms.push_back(std::make_shared<BattleRoom>(movement, mask, nice));
            } else {
                rooms.push_back(std::make_shared<EmptyRoom>(movement, mask, nice));
            }
        }
    }

    // Enter the room
    bool exit = false;
    while (!exit) {
        std::cout << "You are at: " << p->x << ", " << p->y << std::endl;
        auto room = rooms[index(p->x, p->y)];
        std::cout << "You enter " << room->GetDesc() << std::endl;
        room->specialAction();
        room->display();

        std::cout << "Movement: " << movement->toString() << std::endl;

        if (movement->leaveFloor) {
            exit = true;
            p->x = 0;
            p->y = 0;
        }

        if (movement->isX) p->x += movement->incX ? 1 : -1;
        if (movement->isY) p->y += movement->incY ? 1 : -1;
        movement->reset();
    }
}
