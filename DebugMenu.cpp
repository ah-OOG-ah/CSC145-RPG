#include "DebugMenu.h"
#include "Menu.h"
#include <iostream>


void returnToOverworld(Menu* menu) {

    std::cout << "Returning to Overworld..." << std::endl;
    menu->display();
}

void enterBattle(Menu* menu) {

    std::cout << "Entering battle!" << std::endl;
    menu->display();
}

void manageInventory(Menu* menu) {

    std::cout << "Entering inventory..." << std::endl;
    menu->display();
}

void enterShop(Menu* menu) {

    std::cout << "Entering Shop..." << std::endl;
    menu->display();
}

void chat(Menu* menu) {

    std::cout << "Entering chat menu..." << std::endl;
    menu->display();
}

void quitGame(Menu* menu) {

    std::cout << "Goodbye!" << std::endl;
}

DebugMenu::DebugMenu() : Menu(std::vector<MenuEntry<Menu*>>({
        MenuEntry<Menu*>("Return to Game", &returnToOverworld),
        MenuEntry<Menu*>("Enter Battle", &enterBattle),
        MenuEntry<Menu*>("Manage Inventory", &manageInventory),
        MenuEntry<Menu*>("Enter Shop", &enterShop),
        MenuEntry<Menu*>("Talk to Someone", &chat),
        MenuEntry<Menu*>("Quit Game", &quitGame)
    })) {}
