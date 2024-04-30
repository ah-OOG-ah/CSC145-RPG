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
    /*
    enterString; Dialogue index of 0; Used when player enters shop
    buyOrSell; Dialogue index of 1; Used when player is asked whether they want to buy or sell
    whatAreYouBuying; //Dialogue index of 2; Used when player are returned to buying menu
    merchantBuying; Dialogue index of 3; Used when player asks to sell
    takeThatFor; Dialogue index of 4; Used when merchant says how much item is worth
    youBought; Dialogue index of 5; Used after players buys an item
    theyBought; Dialogue index of 6; Used after merchant buys an item
    notEnough; Dialogue index of 7; Used when player does not have enough money to buy an item
    invalid; Dialogue index of 8; Used when player inputs an invalid input
    youHaveNotEnough; Dialogue index of 9; Used when player tries to sell more than they have
    merchantHaveNotEnough; Dialogue index of 10; Used when player tries to buy more than the merchant has
    amountSelling; Dialogue index of 11; Used when player is trying to sell
    exitString; Dialogue index of 12; Used when player leaves the shop
    giveBack; Dialogue index of 13; Used when player buys when inventory is full and they do not replace any items in inventory
    failedSale; Dialogue index of 14; Used when player says no to buying item
    howMany; Dialogue index of 15; Used to ask player how many of item they are buying
    */ 
};