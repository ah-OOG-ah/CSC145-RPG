#pragma once

#include "Room.h"


class EmptyRoom : public Room {
  protected:
    std::string mapDisplay = "-";
    //Room with no real features
  public:
    EmptyRoom(std::shared_ptr<Movement> m, uint8_t mask, int64_t nice);
};
