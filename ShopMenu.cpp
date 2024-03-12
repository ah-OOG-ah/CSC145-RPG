#include "ShopMenu.h"
#include <cstdint>
#include <string>

ShopMenu::ShopMenu(std::string merchant, std::vector<std::string> entries, Item* stock1, Item* stock2, Item* stock3) : Menu(entries)
{
    merchantName = merchant;
    purchase1 = stock1;
    purchase2 = stock2;
    purchase3 = stock3;
}



