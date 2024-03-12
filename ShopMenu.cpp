#include "ShopMenu.h"
#include <cstdint>
#include <string>
#include <iostream>
#include <ostream>
#include <vector>
#include "inventory.h"

ShopMenu::ShopMenu(std::string merchant, std::vector<std::string> entries, Item* stock1, Item* stock2, Item* stock3) : Menu(entries)
{
    merchantName = merchant;
    purchase1 = stock1;
    purchase2 = stock2;
    purchase3 = stock3;
}

void ShopMenu::display()
{
    std::cout<<entries[0]<<std::endl;
    
    int64_t choice;
    while(choice != -1)
    {
        
    }
    std::cout<<entries[8]<<std::endl;
}

void ShopMenu::dispatch(int64_t choice)
{
    switch(choice)
    case 1: 
}



