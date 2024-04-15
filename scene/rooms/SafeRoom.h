#pragma once

#include "Room.h"


class SafeRoom : public Room {
  protected:
    std::string mapDisplay = "M"; // "M" for Main

  public:
    explicit SafeRoom(std::string name);
};
