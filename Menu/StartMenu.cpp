#include <iostream>
#include "StartMenu.h"
#include "game.h"

StartMenu::StartMenu() : Menu(std::vector<std::string>({
    "Enter the Tower",
    "Run like a pansy"
})) {}

StartMenu::~StartMenu() {

    delete this->floor;
}

void StartMenu::enterTower() {

    if (getLevel() != 0) {

        std::cerr << "Unexpected state! Tried to enter the tower through a window (floor is not 0)" << std::endl;
        std::cerr << "Quitting!" << std::endl;
        return;
    }

    std::cout << "You enter the tower. A foreboding feeling sinks into your skin, and the faint sound of howls echoes in the distance." << std::endl;
    std::cout << "It's mildly unsettling, but the rewards will be worth a little discomfort." << std::endl;
    newFloor();
    getTower().run();
}

void StartMenu::dispatch(int64_t i) {

    if (i == 0)
        this->enterTower();
}
