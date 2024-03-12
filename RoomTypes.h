#pragma once

#include <string>
#include "item.h"
#include "Room.h"
#include "ShopMenu.h"
#include <cstdint>
#include <vector>

class SafeRoom : public Room
{
    protected:
    std::string mapDisplay = "M"; // "M" for Main 
    public:
    /*
    Name: GenerateRoom
    Return type: void
    Arguments: 5 int64_t integers
    Use: Only uses the first integer passed in. It uses it in a switch statement to determine the description of the room
    */
    void GenerateRoom(int64_t ran1, int64_t ran2, int64_t ran3, int64_t ran4, int64_t ran5) override;
};

class BattleRoom : public Room
{
    protected:
    //SpawnTable
    std::string mapDisplay = "B";
    Item* treasure = nullptr;

    public: 
    /*
    Name: GetTreasure
    Return type: Item pointer
    Arguments: None
    Use: Returns the "treasure" Item pointer
    */
    Item* GetTreasure();
    /*
    Name: GenerateRoom
    Return type: void
    Arguments: 5 int64_t integers
    Use: FULL IMPLEMENTATION DETAILS ON THE WAY
    */
    void GenerateRoom(int64_t ran1, int64_t ran2, int64_t ran3, int64_t ran4, int64_t ran5) override;
};

class TreasureRoom : public Room
{   
    protected:
    //SpawnTable
    std::string mapDisplay = "T";
    Item* treasure = nullptr;
    Item* treasure2 = nullptr;

    public:
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
    void GenerateRoom(int64_t ran1, int64_t ran2, int64_t ran3, int64_t ran4, int64_t ran5) override;
};


class HallWay : public Room
{   
    protected:
    std::string mapDisplay = "-";

    public:
    void GenerateRoom(int64_t ran1, int64_t ran2, int64_t ran3, int64_t ran4, int64_t ran5) override;
};

class Shop : public Room
{
    protected:
    std::string mapDisplay = "S";
    std::string merchantName;
    Item* purchase1 = nullptr;
    Item* purchase2 = nullptr;
    Item* purchase3 = nullptr;
    std::vector<std::string> entries;
    /* 
    enterString; //Dialogue index of 1; Used when player enters shop
    whatAreYouBuying; //Dialogue index of 2; Used when player are returned to buying menu
    merchantBuying; //Dialogue index of 3; Used when player asks to sell
    takeThatFor; //Dialogue index of 4; Used when merchant says how much item is worth
    youBought; //Dialogue index of 5; Used after players buys an item
    theyBought; //Dialogue index of 6; Used after merchant buys an item
    notEnough; //Dialogue index of 7; Used when player does not have enough money to buy an item
    exitString; //Dialogue index of 8; Used when player leaves the shop*/

    public:
    ShopMenu shop;
    /*
    Name: GetMerchant
    Return type: string
    Arguments: None
    Use: returns the "merchant" string
    */
    std::string GetMerchant();
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
    void GenerateRoom(int64_t ran1, int64_t ran2, int64_t ran3, int64_t ran4, int64_t ran5) override;

    
};