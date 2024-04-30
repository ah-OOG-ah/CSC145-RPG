#pragma once

#include "Menu.h"
#include "Item.h"
#include "Equipment.h"
#include "scene/rooms/ShopDialogue.h"
#include <cstdint>
#include <string>


class ShopMenu : public Menu {

  public:
    ShopMenu(std::string merchant, const Dialogue& text, const std::vector<std::shared_ptr<Item>>& wares);
    void display() override;

  protected:
    // Technically, this just duplicates the menu entries. But it's much easier to use.
    Dialogue text;

    void dispatch(int64_t i) override;

  private:
    std::string merchantName;
    std::vector<std::shared_ptr<Item>> wares;
    std::shared_ptr<Item> purchase1;
    std::shared_ptr<Item> purchase2;
    std::shared_ptr<Item> purchase3;
    std::shared_ptr<Item> GetPurchase(int64_t);

    void Buy();
    void Sell();
};