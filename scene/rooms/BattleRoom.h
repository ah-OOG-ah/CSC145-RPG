#pragma once

#include "Item.h"
#include "Room.h"
#include "scene/Battle.h"


class BattleRoom : public Room {
  protected:
    std::string mapDisplay = "B";
    Battle b;
    //Room with enemies that attack. Enemies will keep appearing whenever room is entered unless the enemies were defeated.
  public:
    BattleRoom(std::shared_ptr<Movement> m, uint8_t mask, int64_t nice);

    void specialAction() override;
};
