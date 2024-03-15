#include "ShopMenu.h"
#include <cstdint>
#include <string>
#include <iostream>
#include <ostream>
#include <vector>
#include "inventory.h"
#include "game.cpp"


ShopMenu::ShopMenu(std::string merchant, std::vector<std::string> entries, Item* stock1, Item* stock2, Item* stock3) : Menu(entries)
{
    merchantName = merchant;
    purchase1 = stock1;
    purchase2 = stock2;
    purchase3 = stock3;
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
            std::cout<< i << ". "<< GetPurchase(i)->GetName() << "x" << GetPurchase(i)->GetAmount() << " Price: " << GetPurchase(i)->GetPrice() << "Gold" <<std::endl;
        }
        std::cout << "4. None of it " << std::endl;
        std::cin>>itemChoice;
        dispatch(itemChoice);
    } while (itemChoice != 4); 
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
    if(player.playerInven.GetElement(choice) != nullptr)
    {
        int64_t amnt = 0;
        do{
        std::cout << merchantName<< ": " << entries[11] << std::endl;
        std::cin>>amnt;
        if(amnt > player.playerInven.GetElement(choice)->GetAmount() || amnt <= 0)
        {
            std::cout << merchantName<< ": " << entries[10] << std::endl;
        }
        }while(amnt <= player.playerInven.GetElement(choice)->GetAmount());
        int64_t total = amnt * player.playerInven.GetElement(choice)->GetPrice();
        //std::cout << merchantName<< ": " << entries[4] << (amnt * player.playerInven.GetElement(choice)->GetAmount()) << " Gold" << std::endl;
        player.playerInven.AddGold(total);
        player.playerInven.GetElement(choice)->ChangeAmount( -1 * amnt);
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
            break;
        default:
            std::cout << merchantName<< ": " << entries[8] << std::endl;
            break;
    }
}