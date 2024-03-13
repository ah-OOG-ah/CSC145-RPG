#include "ShopMenu.h"
#include <cstdint>
#include <string>
#include <iostream>
#include <ostream>
#include <istream>
#include <vector>
#include "inventory.h"

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
        for(int i = 1; i <= 3; i++)
        {
            std::cout<< i << ". "<< GetPurchase(i)->GetName() << "x" << GetPurchase(i)->GetAmount() << " Price: " << GetPurchase(i)->GetPrice() << "Gold" <<std::endl;
        }
        std::cout << "4. None of it " << std::endl;
        std::getline(std::cin, itemChoice);
        dispatch(itemChoice);
    } while (itemChoice != 4); 
}

void ShopMenu::Sell()
{
    std::cout << merchantName<< ": " << entries[3] << std::endl;
    //Inventory while loop to display
    //Actual selling
    std::cout << merchantName<< ": " << entries[6] << std::endl;
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
        std::cout<<"1. I want to buy"<<std::endl;
        std::cout<<"2. I want to sell"<<std::endl;
        std::cout<<"3. I was just leaving"<<std::endl;
        std::getline(std::cin, choice);
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
                std::cout << merchantName<< ": " << << entries[8] << std::endl;
        }
    }
    std::cout << merchantName<< ": " << entries[9] <<std::endl;
}

void ShopMenu::dispatch(int64_t choice)
{
    switch(choice)
    {
        case 1:
            //if Gold is not enough
            //else {
            //Push back Purchase1
            //Subtract price of Purchase1 from Inventory's Gold
            std::cout << merchantName<< ": " << entries[5] << std::endl;
            break;
        case 2:
            //if Gold is not enough
            //else {
            //Push back Purchase2
            //Subtract price of Purchase2 from Inventory's Gold
            std::cout << merchantName<< ": " << entries[5] << std::endl;
            break;
        case 3:
            //if Gold is not enough
            //else {
            //Push back Purchase3
            //Subtract price of Purchase3 from Inventory's Gold
            std::cout << merchantName<< ": " << entries[5] << std::endl;
            break;
        case 4:
            break;
        default:
            std::cout << merchantName<< ": " << entries[8] << std::endl;
            break;
    }
}