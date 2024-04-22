#include <string>
#include <utility>
#include "Room.h"
#include "game.h"


const std::vector<Direction> Room :: directions ({
    Direction("North", [](const std::shared_ptr<Movement>& m){ m->isY = true; m->incY = false; }),
    Direction("South", [](const std::shared_ptr<Movement>& m){ m->isY = true; m->incY = true; }),
    Direction("East", [](const std::shared_ptr<Movement>& m){ m->isX = true; m->incX = false; }),
    Direction("West", [](const std::shared_ptr<Movement>& m){ m->isX = true; m->incX = true; })
});

Room::Room(std::string name, std::shared_ptr<Movement> m, uint8_t mask) : Room(std::move(name), "", std::move(m), mask) { }
Room::Room(std::string name, std::string description, std::shared_ptr<Movement> m, uint8_t mask)
    : Menu(std::vector<std::string>()), roomName(std::move(name)), description(std::move(description)), movement(std::move(m)) {

    // By default, doesn't add a special action
    // That's handled by the room instances
    // This just adds the directions and the related functions
    for (size_t i = 0; i < 4; ++i) {
        if (mask >> (3 - i) & 0b1) {
            entries.push_back(directions[i].name);
            funcs.emplace_back([this, i](){ directions[i].func(this->movement); });
        }
    }
}

Room::~Room() = default;

std::string Room::GetName() const { return roomName; }

std::string Room::GetDesc() const { return description; }

std::string Room::GetMapDisplay() const { return isExplored ? mapDisplay : "\?"; }

void Room::setMovement(std::shared_ptr<Movement> m) {
    movement = std::move(m);
}

void Room::dispatch(int64_t i) {
    funcs[i]();
}

void Room::specialAction() {
    // Override this to make your room Special (TM)!
}
