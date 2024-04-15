#pragma once

#include "Room.h"


class EmptyRoom : public Room {
  protected:
    std::string mapDisplay = "-";

  public:
    explicit EmptyRoom(std::string name);
};
