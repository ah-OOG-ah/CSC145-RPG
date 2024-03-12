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
    std::cout<<entries[0]<<std::endl;
    
    int64_t choice;
    while(choice > 0 && choice <=2)
    {
        std::cout<<entries[1]<<std::endl;
        std::cout<<"1. I want to buy"<<std::endl;
        std::cout<<"2. I want to sell"<<std::endl;
        std::cout<<"3. I was just leaving"<<std::endl;
        std::getline(std::cin, choice);
        switch(choice)
        {
            case 1:
                int64_t itemChoice = 0;
                do
                {    
                std::cout<<entries[2]<<std::endl;
                    for(int i = 1; i <= 3; i++)
                    {
                        std::cout<< i << ". "<< GetPurchase(i)->GetName() << "x" << GetPurchase(i)->GetAmount() << " Price: " << GetPurchase(i)->GetPrice() << "Gold" <<std::endl;
                    }
                    std::cout << "4. None of it " << std::endl;
                    std::getline(std::cin, itemChoice);
                    dispatch(itemChoice);
                } while (itemChoice != 4);
                break;
            case 2:
        }
    }
    std::cout<<entries[9]<<std::endl;
}

void ShopMenu::dispatch(int64_t choice)
{
    switch(choice)
    {
        case 1:
            //Push back Purchase1
            //Subtract price of Purchase1 from Inventory's Gold
            std::cout<< entries[5] << std::endl;
            break;
        case 2:
            //Push back Purchase2
            //Subtract price of Purchase2 from Inventory's Gold
            std::cout<< entries[5] << std::endl;
            break;
        case 3:
            //Push back Purchase3
            //Subtract price of Purchase3 from Inventory's Gold
            std::cout<< entries[5] << std::endl;
            break;
        case 4:
            break;
        default:
            std::cout<< entries[8] << std::endl;
            break;
    }
}