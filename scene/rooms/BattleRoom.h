#pragma once

#include "Item.h"
#include "Room.h"


class BattleRoom : public Room {
  protected:
    //SpawnTable
    std::string mapDisplay = "B";
    Item* treasure = nullptr;

  public:
    BattleRoom(std::shared_ptr<Movement> m, uint8_t mask);

    /*
    Name: GetTreasure
    Return type: Item pointer
    Arguments: None
    Use: Returns the "treasure" Item pointer
    */
    Item* GetTreasure();
};
