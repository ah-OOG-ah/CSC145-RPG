#include "Battle.h"
#include "Enemy.h"
#include "scene/Scene.h"
#include "game.h"
#include <string>
#include <utility>
#include <vector>
#include <iostream>

Battle::Battle(std::string name) : Scene(std::move(name)), Menu(std::vector<std::string>({
    "Attack",
    "Escape"
})) {

    this->player = getPlayer();
    this->enemy = std::vector<Enemy>();
    //this->enemy.emplace_back(10);
}

/**
 * First, the player should get the Battle menu
 * Then, the player acts
 * Then, the enemy acts
 * Then, the battle checks if a side is dead; repeat
 */
void Battle::run() {

    std::cout << "The battle of " << name << " begins!" << std::endl;

    while (true) {

        std::cout << "\nYou see the enemy: " << std::endl;
        this->listEnemies();

        this->display();

        if (this->player->getFleeing() || this->player->getCurrentHp() < 1) {
            this->player->setFleeing(false);
            std::cout << "You have been defeated." << std::endl;
            // TODO: monkey bob reference?
            break;
        } else if (enemy.empty()) {
            std::cout << "Victory!" << std::endl;
            break;
        }
    }
}

void Battle::listEnemies() {
    for (Enemy e : enemy)
        std::cout << e.toString() << std::endl;
}

void Battle::attack() {

    player->attackEntity(&enemy.at(0));
    this->listEnemies();
    std::erase_if(enemy, [](Enemy e){ return !e.getAlive(); });
}

void Battle::escape() {

    this->player->setFleeing(true);
}

void Battle::dispatch(int64_t i) {
    switch (i) {
        case 0: this->attack(); break;
        case 1: this->escape(); break;
        default: {
            std::cout << "Unexpected state! Things may break!" << std::endl;
        }
    }
}
