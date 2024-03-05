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

    std::string Shop::GetDialogue(int64_t selection)
    {
        switch(selection)
        {
            case1:
                return enterString;
                break;
            case 2:
                return whatAreYouBuying;
                break;
            case 3:
                return bought;
                break;
            case 4:
                return notEnough;
                break;
            case 5: 
                return exitString;
                break;
            default:
                return "Monkey Bob is coming for you";
                break;
        }
    }
    void Shop::GenerateRoom(int64_t ran1, int64_t ran2, int64_t ran3, int64_t ran4, int64_t ran5)
    {
        //Switches Statement to determine Purchase1-3

        //Switch statement to determine dialogue choices

        //Multi switch statement to determine merchant's name
        switch(ran1)
        {
            case 1:
                enterString = "Hello me chum, welcome to me shop";
                whatAreYouBuying = "Which of me fine items would ye be interested in buying today";
                bought = "Aye! Pleasure doing buisness";
                notEnough = "Oi! You do not have enough money, lad! Get a job!";
                exitString = "Take care of yeself, mate!";
                switch(ran2)
                {
                    case 1:
                        merchantName = "Grisly Beard";
                        break;
                    case 2:
                        merchantName = "Jerome";
                        break;
                    case 3:
                        merchantName = "Jackson";
                        break;
                    default:
                        merchantName = "Hobo Gregor";
                        break;
                }
                break;
            case 2:
                enterString = "Welcome, sir, to my shop!";
                whatAreYouBuying = "Which item would you be interested in today\?";
                bought = "Much apprieciated, sir!";
                notEnough = "It seems you do not have enough money for that item at the moment.";
                exitString = "Have a blessed day, sire!";
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
                        merchantName = "Sir Michel";
                        break;
                }
                break;
            case 3:
                enterString = "Hello there!";
                whatAreYouBuying = "Anything you interested in\?";
                bought = "Oh, Money, you do make the world go round!";
                notEnough = "Hey, rat! You don\'t seem to have enough money to buy that";
                exitString = "Be careful. You never know what could be lurking out there";
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
                enterString = "((|)..(|)) \n     -";
                whatAreYouBuying = "What are you buying\?";
                bought = "This will make a good offering for the boss";
                notEnough = "Monkey Bob did not like that";
                exitString = "Monkey Bob is coming for you";
                merchantName = "Bob";
        }
    }