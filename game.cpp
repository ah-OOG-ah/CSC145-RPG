#include "Menu.h"
#include <iostream>
#include <ostream>
#include <string>
#include <vector>

bool returnToOverworld() {

    std::cout << "Returning to Overworld..." << std::endl;
    return false;
}

bool enterBattle() {

    std::cout << "Entering battle!" << std::endl;
    return false;
}

bool manageInventory() {

    std::cout << "Entering inventory..." << std::endl;
    return false;
}

bool enterShop() {

    std::cout << "Entering Shop..." << std::endl;
    return false;
}

bool chat() {

    std::cout << "Entering chat menu..." << std::endl;
    return false;
}

bool quitGame() {

    std::cout << "Goodbye!" << std::endl;
    return true;
}

int main() {

    Menu debugMenu(std::vector<MenuEntry>({
        MenuEntry("Return to Game", &returnToOverworld),
        MenuEntry("Enter Battle", &enterBattle),
        MenuEntry("Manage Inventory", &manageInventory),
        MenuEntry("Enter Shop", &enterShop),
        MenuEntry("Talk to Someone", &chat),
        MenuEntry("Quit Game", &quitGame)
    }));

    while (!debugMenu.display()) {}
}
