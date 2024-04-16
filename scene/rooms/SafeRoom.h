#pragma once

#include "Room.h"


class SafeRoom : public Room {
  protected:
    std::string mapDisplay = "M"; // "M" for Main

  public:
    explicit SafeRoom(std::shared_ptr<Movement> m, uint8_t mask);
};
