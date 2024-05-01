#pragma once

#include <string>
#include "Item.h"
#include "Room.h"
#include "ShopMenu.h"
#include "ShopDialogue.h"
#include <cstdint>
#include <vector>


class ShopRoom : public Room {
  protected:
    std::string mapDisplay = "S";
    std::unique_ptr<ShopMenu> shopMenu;
    //Room that contains a shop. Enter shop will be one of the options when you enter the room.
  public:
    ShopRoom(std::shared_ptr<Movement> m, uint8_t mask, int64_t nice);
};