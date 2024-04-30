#pragma once

#include "Menu.h"
#include "Item.h"
#include "Equipment.h"
#include "scene/rooms/ShopDialogue.h"
#include <cstdint>
#include <string>


class ShopMenu : public Menu {

  public:
    ShopMenu(std::string merchant, const Dialogue& text, std::shared_ptr<Item> stock1, std::shared_ptr<Item> stock2, std::shared_ptr<Item> stock3);
    void display() override;

  protected:
    void dispatch(int64_t i) override; //Called by buy to actually give player's the items

  private:
    std::string merchantName;
    std::shared_ptr<Item> purchase1 = nullptr;
    std::shared_ptr<Item> purchase2 = nullptr;
    std::shared_ptr<Item> purchase3 = nullptr;
    std::shared_ptr<Item> GetPurchase(int64_t);

    void Buy();
    void Sell();
};