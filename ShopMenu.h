#pragma once

#include "Menu.h"
#include "Item.h"
#include "Equipment.h"
#include "scene/rooms/ShopDialogue.h"
#include <cstdint>
#include <string>


/**
 * This doesn't lend itself to the Menu class, so it gets it's own class.
 */
class ShopMenu  {

  public:
    ShopMenu(std::string merchant, Dialogue  text, std::vector<std::shared_ptr<Item>> wares);
    void displayOnce();

  protected:
    Dialogue text;
    std::string merchantName;
    std::vector<std::shared_ptr<Item>> wares;

    /**
     * These run the respective dialogues once, then return.
     */
    void Buy();
    void Sell();

    void displayMany(int64_t &i, bool &exit);
};