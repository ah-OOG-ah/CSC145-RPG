#pragma once

#include "Item.h"
#include "Room.h"
#include "MenuNode.h"
#include "scene/Battle.h"


/**
 * Treasure rooms also contain a "wise entity". Speak well, and you'll be rewarded. Speak poorly... and eat lead.
 */
class TreasureRoom : public Room {
  protected:
    std::string mapDisplay = "T";
    std::shared_ptr<Item> treasure;
    std::shared_ptr<MenuNode> dialogueHead;
    std::string entityName;
    std::unique_ptr<Battle> battle;
    bool skip = false;

  public:
    TreasureRoom(std::shared_ptr<Movement> m, uint8_t mask, int64_t nice);
    void specialAction() override;
};
