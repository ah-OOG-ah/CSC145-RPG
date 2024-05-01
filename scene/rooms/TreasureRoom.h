#pragma once

#include "Item.h"
#include "Room.h"


/**
 * Treasure rooms also contain a "wise entity". Speak well, and you'll be rewarded. Speak poorly... and eat lead.
 */
class TreasureRoom : public Room {
  protected:
    std::string mapDisplay = "T";
    std::shared_ptr<Item> treasure;

  public:
    TreasureRoom(std::shared_ptr<Movement> m, uint8_t mask, int64_t nice);
};
