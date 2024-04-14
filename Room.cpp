#include <string>
#include <utility>
#include "Room.h"
#include "game.h"

Room::Room(std::string name) : roomName(std::move(name)) { }
Room::Room(std::string name, std::string description) : roomName(std::move(name)), description(std::move(description)) { }

Room::~Room() = default;

std::string Room::GetName() const { return roomName; }

std::string Room::GetDesc() const { return description; }

std::string Room::GetMapDisplay() const { return isExplored ? mapDisplay : "\?"; }
