#pragma once

#include "Menu.h"
#include "Item.h"
#include "Equipment.h"
#include "scene/rooms/ShopDialogue.h"
#include <cstdint>
#include <string>


class ShopMenu : public Menu {

  public:
    ShopMenu(std::string merchant, Dialogue  text, std::vector<std::shared_ptr<Item>> wares);
    void display() override;

  protected:
    // Technically, this just duplicates the menu entries. But it's much easier to use.
    Dialogue text;

    void dispatch(int64_t i) override;

  private:
    std::string merchantName;
    std::vector<std::shared_ptr<Item>> wares;

    void Buy();
    void Sell();
};