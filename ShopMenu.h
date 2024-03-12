#pragma once

#include "Menu.h"
#include "item.h"
#include <cstdint>
#include <string>

class ShopMenu : public Menu {

  public:
    ShopMenu(std::string merchant, std::vector<std::string> entries, Item* stock1, Item* stock2, Item* stock3);

  protected:
    void display() override;
    virtual void dispatch(int64_t i) override;

  private:
    std::string merchantName;
    Item* purchase1 = nullptr;
    Item* purchase2 = nullptr;
    Item* purchase3 = nullptr;
    Item* GetPurchase(int64_t);

    /*
    enterString; //Dialogue index of 0; Used when player enters shop
    buyOrSell; Dialogue index of 1; Used when player is asked whether they want to buy or sell
    whatAreYouBuying; //Dialogue index of 2; Used when player are returned to buying menu
    merchantBuying; //Dialogue index of 3; Used when player asks to sell
    takeThatFor; //Dialogue index of 4; Used when merchant says how much item is worth
    youBought; //Dialogue index of 5; Used after players buys an item
    theyBought; //Dialogue index of 6; Used after merchant buys an item
    notEnough; //Dialogue index of 7; Used when player does not have enough money to buy an item
    invalid; //Dialogue index of 8; Used when player inputs an invalid input
    exitString; //Dialogue index of 9; Used when player leaves the shop*/
};