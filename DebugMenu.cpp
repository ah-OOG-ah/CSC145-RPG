#include "DebugMenu.h"
#include "Battle.h"
#include "Menu.h"
#include <iostream>
#include <ostream>
#include <string>


void DebugMenu::returnToOverworld() {

    std::cout << "Returning to Overworld..." << std::endl;
    this->display();
}

void DebugMenu::enterBattle() {

    std::cout << "To battle!" << std::endl;
    Battle battle(std::string("debug_fight"));
    battle.run();
    this->display();
}

void DebugMenu::manageInventory() {

    std::cout << "Entering inventory..." << std::endl;
    this->display();
}

void DebugMenu::enterShop() {

    std::cout << "Entering Shop..." << std::endl;
    this->display();
}

void DebugMenu::chat() {

    std::cout << "Entering chat menu..." << std::endl;
    this->display();
}

void DebugMenu::quitGame() {

    std::cout << "Goodbye!" << std::endl;
}

DebugMenu::DebugMenu() : Menu(std::vector<std::string>({
    "Return to Game",
    "Enter Battle",
    "Manage Inventory",
    "Enter Shop",
    "Talk to Someone",
    "Quit Game"
})) {}

void DebugMenu::dispatch(int64_t i) {

    switch (i) {
        case 0: this->returnToOverworld(); break;
        case 1: this->enterBattle(); break;
        case 2: this->manageInventory(); break;
        case 3: this->enterShop(); break;
        case 4: this->chat(); break;
        case 5: this->quitGame(); break;
        default: {
            std::cout << "Unexpected state! Things may break!" << std::endl;
        }
    }
}
