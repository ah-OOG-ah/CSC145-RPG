#include "BattleMenu.h"
#include "Battle.h"
#include "Menu.h"
#include "game.h"
#include <cstdint>
#include <iostream>
#include <string>
#include <tuple>

void BattleMenu::attack() {
    
    
}

void BattleMenu::escape() {
    
    this->player->setFleeing(true);
}

BattleMenu::BattleMenu() : Menu(std::vector<std::string>({
    "Attack",
    "Escape"
})) {

    this->player = getPlayer();
}

void BattleMenu::dispatch(int64_t i) {
    switch (i) {
        case 0: this->attack(); break;
        case 1: this->escape(); break;
        default: {
            std::cout << "The heck-";
            int* p = nullptr; *p = 0;
        }
    }
}
