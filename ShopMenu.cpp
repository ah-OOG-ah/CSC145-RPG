#include "ShopMenu.h"
#include <cstdint>
#include <string>
#include <iostream>
#include <ostream>
#include <vector>
#include "inventory.h"
#include "game.cpp"


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
    merchantHaveNotEnough; Dialogue index of 10; Used when player tries to buy than the merchant has
    exitString; Dialogue index of 11; Used when player leaves the shop
    */ 

ShopMenu::ShopMenu(std::string merchant, std::vector<std::string> entries, Item* stock1, Item* stock2, Item* stock3, Equipment* equipStock1) : Menu(entries)
{
    merchantName = merchant;
    purchase1 = stock1;
    purchase2 = stock2;
    purchase3 = stock3;
    equip1 = equipStock1;
}

void ShopMenu::Buy()
{
    int64_t itemChoice = 0;
    do
    {    
        std::cout << merchantName << ": " <<entries[2]<<std::endl;
        std::cout << "GOLD" << player.playerInven.GetGold() << std::endl;
        for(int i = 1; i <= 3; i++)
        {
            std::cout<< i << ". " << GetPurchase(i)->GetName() << "x" << GetPurchase(i)->GetAmount() << "   Price: " << GetPurchase(i)->GetPrice() << std::endl;
        }
        std::cout <<"4. " << equip1->GetName() << "   Price: " << equip1->GetPrice() << std::endl;
        std::cout << "5. None of it " << std::endl;
        std::cin>>itemChoice;
        dispatch(itemChoice);
    } while (itemChoice != 5); 
}

void ShopMenu::Sell()
{
    std::string choice;
    do
    {
    std::cout << merchantName<< ": " << entries[3] << std::endl;
    std::cout << "Enter \"Nothing\" or \"Exit\" to exit this menu" << std::endl;
    player.playerInven.PrintInven();
    std::getline(std::cin, choice);
    if(player.playerInven.GetItem(choice) != nullptr)
    {
        int64_t amnt = 0;
        do{
        std::cout << merchantName<< ": " << entries[11] << std::endl;
        std::cin>>amnt;
        if(amnt > player.playerInven.GetItem(choice)->GetAmount() || amnt <= 0)
        {
            std::cout << merchantName<< ": " << entries[10] << std::endl;
        }
        }while(amnt <= player.playerInven.GetItem(choice)->GetAmount());
        int64_t total = amnt * player.playerInven.GetItem(choice)->GetPrice();
        //std::cout << merchantName<< ": " << entries[4] << (amnt * player.playerInven.GetElement(choice)->GetAmount()) << " Gold" << std::endl;
        player.playerInven.AddGold(total);
        player.playerInven.GetItem(choice)->ChangeAmount( -1 * amnt);
        std::cout << total << "Gold added to Inventory" << std::endl;
        std::cout << merchantName<< ": " << entries[6] << std::endl;
    }
    else
    {
        std::cout << merchantName<< ": " << entries[8] << std::endl;
    }
    } while(choice != "Nothing" || choice != "nothing" || choice != "NOTHING" || choice != "Exit" || choice != "exit" || choice != "EXIT");
}

Item* ShopMenu::GetPurchase(int64_t selection)
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

void ShopMenu::display()
{
    std::cout << merchantName<< ": " << entries[0] <<std::endl;
    
    int64_t choice = 0;
    while(choice != 3)
    {
        std::cout << merchantName<< ": " << entries[1] <<std::endl;
        std::cout << "GOLD" << player.playerInven.GetGold() << std::endl;
        std::cout<<"1. I want to buy"<<std::endl;
        std::cout<<"2. I want to sell"<<std::endl;
        std::cout<<"3. I was just leaving"<<std::endl;
        std::cin>>choice;
        switch(choice)
        {
            case 1:
                Buy();
                break;
            case 2:
                Sell();
                break;
            case 3:
                break;
            default:
                std::cout << merchantName<< ": " << entries[8] << std::endl;
        }
    }
    std::cout << merchantName<< ": " << entries[12] <<std::endl;
}

void ShopMenu::dispatch(int64_t choice)
{
    switch(choice)
    {
        case 1:
            if(player.playerInven.GetGold() < purchase1->GetPrice())
            {
                std::cout << merchantName<< ": " << entries[7] <<std::endl;
                return;
            }
            else {
                player.playerInven.PushBack(purchase1);
                player.playerInven.AddGold(-1 * purchase1->GetPrice());
                std::cout << purchase1->GetName() << " Added to Inventory" << std::endl;
                std::cout << purchase1->GetPrice() << " Given to " << merchantName << std::endl;
                std::cout << merchantName<< ": " << entries[5] << std::endl;
            }
            break;
        case 2:
            if(player.playerInven.GetGold() < purchase2->GetPrice())
            {
                std::cout << merchantName<< ": " << entries[7] <<std::endl;
                return;
            }
            else {
                player.playerInven.PushBack(purchase2);
                player.playerInven.AddGold(-1 * purchase2->GetPrice());
                std::cout << purchase1->GetName() << " Added to Inventory" << std::endl;
                std::cout << purchase1->GetPrice() << " Given to " << merchantName << std::endl;
                std::cout << merchantName<< ": " << entries[5] << std::endl;
            }
            break;
        case 3:
            if(player.playerInven.GetGold() < purchase3->GetPrice())
            {
                std::cout << merchantName<< ": " << entries[7] <<std::endl;
                return;
            }
            else {
                player.playerInven.PushBack(purchase3);
                player.playerInven.AddGold(-1 * purchase3->GetPrice());
                std::cout << purchase1->GetName() << " Added to Inventory" << std::endl;
                std::cout << purchase1->GetPrice() << " Given to " << merchantName << std::endl;
                std::cout << merchantName<< ": " << entries[5] << std::endl;
            }
            break;
        case 4:
            if(player.playerInven.GetGold() < equip1->GetPrice())
            {
                std::cout << merchantName<< ": " << entries[7] <<std::endl;
                return;
            }
            else {
                player.playerInven.PushBack(purchase1);
                player.playerInven.AddGold(-1 * purchase1->GetPrice());
                std::cout << purchase1->GetName() << " Added to Inventory" << std::endl;
                std::cout << purchase1->GetPrice() << " Given to " << merchantName << std::endl;
                std::cout << merchantName<< ": " << entries[5] << std::endl;
            }
            break;
        case 5:
            break;
        default:
            std::cout << merchantName<< ": " << entries[8] << std::endl;
            break;
    }
}