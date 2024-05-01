#pragma once

#include "Item.h"
#include "Room.h"
#include "scene/Battle.h"


class BattleRoom : public Room {
  protected:
    std::string mapDisplay = "B";
    Battle b;

  public:
    BattleRoom(std::shared_ptr<Movement> m, uint8_t mask, int64_t nice);

    void specialAction() override;
};
