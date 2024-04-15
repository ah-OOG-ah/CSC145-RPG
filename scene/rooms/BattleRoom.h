#pragma once

#include "Item.h"
#include "Room.h"


class BattleRoom : public Room {
  protected:
    //SpawnTable
    std::string mapDisplay = "B";
    Item* treasure = nullptr;

  public:
    BattleRoom();

    /*
    Name: GetTreasure
    Return type: Item pointer
    Arguments: None
    Use: Returns the "treasure" Item pointer
    */
    Item* GetTreasure();
};
