#include <string>
#include <utility>
#include "Room.h"
#include "game.h"

Room::Room(std::string name, std::shared_ptr<Movement> m) : Room(std::move(name), "", std::move(m)) { }
Room::Room(std::string name, std::string description, std::shared_ptr<Movement> m)
    : Scene(name), roomName(std::move(name)), description(std::move(description)), movement(std::move(m)) { }

Room::~Room() = default;

std::string Room::GetName() const { return roomName; }

std::string Room::GetDesc() const { return description; }

std::string Room::GetMapDisplay() const { return isExplored ? mapDisplay : "\?"; }

void Room::setMovement(std::shared_ptr<Movement> m) {
    movement = std::move(m);
}
