#pragma once

#include "Item.h"
#include "Room.h"


class TreasureRoom : public Room {
  protected:
    //SpawnTable
    std::string mapDisplay = "T";
    Item* treasure = nullptr;
    Item* treasure2 = nullptr;

  public:
    explicit TreasureRoom(std::shared_ptr<Movement> m, uint8_t mask);

    /*
    Name: GetTreasure
    Return type: Item pointer
    Arguments: None
    Use: Returns the "treasure" Item pointer
    */
    Item* GetTreasure();
    /*
    Name: GetTreasure
    Return type: Item pointer
    Arguments: None
    Use: Returns the "treasure2" Item pointer
    */
    Item* GetTreasure2();
};
