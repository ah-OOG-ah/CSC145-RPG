#include "RoomTypes.h"
#include <string>
#include "item.h"
#include "Room.h"
#include <cstdint>

void SafeRoom::GenerateRoom(int64_t ran1, int64_t ran2, int64_t ran3, int64_t ran4, int64_t ran5)
{
    switch (ran1)
    {
    case 1:
        description = "You enter a blank room with a small lantern hanging form the ceiling in the center";
        break;
    case 2:
        description = "You enter a peaceful room covered in moss. A small fountain is in the center";
    case 3:
        description = "You enter a room covered in cobwebs. No enemies seem to be near... nor anything alive";
    default:
        description = "You enter a room with a mop. Not much to look at";
        break;
    }
}

Item* BattleRoom::GetTreasure() { return treasure; }

void BattleRoom::GenerateRoom(int64_t ran1, int64_t ran2, int64_t ran3, int64_t ran4, int64_t ran5)
{
    switch (ran1)
    {
    case 1:
        description = "You enter a blank room with a small lantern hanging form the ceiling in the center";
        break;
    case 2:
        description = "You enter a peaceful room covered in moss. A small fountain is in the center";
    case 3:
        description = "You enter a room covered in cobwebs. No enemies seem to be near... nor anything alive";
    default:
        description = "You enter a room with a mop. Not much to look at";
        break;
    }
    //Switch statement for spawn table

    //Switch statement for treasure 
}

Item* TreasureRoom::GetTreasure() { return treasure; }
Item* TreasureRoom::GetTreasure2() { return treasure2; }

void TreasureRoom::GenerateRoom(int64_t ran1, int64_t ran2, int64_t ran3, int64_t ran4, int64_t ran5)
{
    switch (ran1)
    {
    case 1:
        description = "You enter a blank room with a small lantern hanging form the ceiling in the center";
        break;
    case 2:
        description = "You enter a peaceful room covered in moss. A small fountain is in the center";
    case 3:
        description = "You enter a room covered in cobwebs. No enemies seem to be near... nor anything alive";
    default:
        description = "You enter a room with a mop. Not much to look at";
        break;
    }
    //Switch statement for spawn table

    //Switch statement for treasure 

    //Switch statement for treasure2
}

void HallWay::GenerateRoom(int64_t ran1, int64_t ran2, int64_t ran3, int64_t ran4, int64_t ran5)
{
    switch (ran1)
    {
    case 1:
        description = "You enter a blank room with a small lantern hanging form the ceiling in the center";
        break;
    case 2:
        description = "You enter a peaceful room covered in moss. A small fountain is in the center";
    case 3:
        description = "You enter a room covered in cobwebs. No enemies seem to be near... nor anything alive";
    default:
        description = "You enter a room with a mop. Not much to look at";
        break;
    }
}

    std::string Shop::GetMerchant() { return merchantName; }
    Item* Shop::GetPurchase(int64_t selection) 
    {
        switch(selection)
        {
            case 1:
                return purchase1;
                break;
            case 2:
                return purchase2;
                break;
            case 3:
                return purchase3;
                break;
            default:
                return nullptr;
                break;
        }
    }
    /*int64_t Shop::GetPrice(int64_t selection)
    {
        switch(selection)
        {
            case 1:
                return price1;
                break;
            case 2:
                return price2;
                break;
            case 3:
                return price3;
                break;
            default:
                return 0;
                break;
        }
    }*/
    void Shop::GenerateRoom(int64_t ran1, int64_t ran2, int64_t ran3, int64_t ran4, int64_t ran5)
    {
        //Switches Statement to determine Purchase1-3

        //Switch statement to determine dialogue choices

        //Multi switch statement to determine merchant's name
        switch(ran1)
        {
            case 1:
                switch(ran2)
                {
                    case 1:
                        merchantName = "Bob";
                        break;
                    case 2:
                        merchantName = "Jerome";
                        break;
                    case 3:
                        merchantName = "Jackson";
                        break;
                    default:
                        merchantName = "Sir Michel";
                        break;
                }
                break;
            case 2:
                switch(ran2)
                {
                    case 1:
                        merchantName = "Hilda";
                        break;
                    case 2:
                        merchantName = "Serena";
                        break;
                    case 3:
                        merchantName = "Sir Jack";
                        break;
                    default:
                        merchantName = "Bruno";
                        break;
                }
                break;
            case 3:
                switch(ran2)
                {
                    case 1:
                        merchantName = "Sam";
                        break;
                    case 2:
                        merchantName = "Aaron";
                        break;
                    case 3:
                        merchantName = "Ridley";
                        break;
                    default:
                        merchantName = "Scott";
                        break;
                }
                break;
            default:
                merchantName = "Merchie the Merchant";
        }
    }