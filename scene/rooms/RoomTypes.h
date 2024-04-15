#pragma once

#include <string>
#include "Item.h"
#include "Room.h"
#include "ShopMenu.h"
#include <cstdint>
#include <vector>

class SafeRoom : public Room {
  protected:
    std::string mapDisplay = "M"; // "M" for Main 
  public:
    explicit SafeRoom(std::string name);
};

class BattleRoom : public Room {
  protected:
    //SpawnTable
    std::string mapDisplay = "B";
    Item* treasure = nullptr;

  public:
    BattleRoom();

    /*
    Name: GetTreasure
    Return type: Item pointer
    Arguments: None
    Use: Returns the "treasure" Item pointer
    */
    Item* GetTreasure();
};

class TreasureRoom : public Room {
  protected:
    //SpawnTable
    std::string mapDisplay = "T";
    Item* treasure = nullptr;
    Item* treasure2 = nullptr;

  public:
    explicit TreasureRoom(std::string name);

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


class HallWay : public Room {
  protected:
    std::string mapDisplay = "-";

  public:
    explicit HallWay(std::string name);
};

class Shop : public Room {
  protected:
    std::string mapDisplay = "S";
    std::string merchantName;
    Item* purchase1 = nullptr;
    Item* purchase2 = nullptr;
    Item* purchase3 = nullptr;

    std::vector<std::string> entries;
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

  public:
    explicit Shop(std::string name);

    /*
    Name: GetMerchant
    Return type: string
    Arguments: None
    Use: returns the "merchant" string
    */
    [[nodiscard]] std::string GetMerchant() const;
    /*
    Name: GetPurchase
    Return type: Item pointer
    Arguments: An int64_t integer from 1-3
    Use: Takes in an integer and returns one of the "purchase" Item pointers based on the integer
    */
    Item* GetPurchase(int64_t);
    /*
    Name: GetPurchase
    Return type: string
    Arguments: An int64_t integer from 1-8
    Use: Takes in an integer and gives the correspong dialogue members based on the number given
    */
    std::string GetDialogue(int64_t);
    void GoToShop();
};