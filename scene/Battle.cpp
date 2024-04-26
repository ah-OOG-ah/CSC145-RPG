#include "Battle.h"
#include "Enemy.h"
#include "scene/Scene.h"
#include "game.h"
#include "enemytiers.h"
#include "PU.h"
#include <string>
#include <utility>
#include <vector>
#include <iostream>


Battle::Battle(std::string name, int64_t nice) : Scene(std::move(name)), Menu(std::vector<std::string>({
    "Attack",
    "Escape"
})) {
    auto numEnemy = randUint() % nice + 5;
    auto src = ETiers::get(nice);

    for (uint64_t i = 0; i < numEnemy; ++i) {
        this->enemy.emplace_back(src[randUint() % src.size()]);
    }
    enemy.erase(enemy.end());
}

/**
 * First, the player should get the Battle menu
 * Then, the player acts
 * Then, the enemy acts
 * Then, the battle checks if a side is dead; repeat
 */
void Battle::run() {

    // TODO: change this
    if (over) return;

    std::cout << "The battle of " << name << " begins!" << std::endl;

    auto ogspd = getPlayer()->getSpd();

    while (true) {

        std::cout << "\nYou see the enemy: " << std::endl;
        this->listEnemies();
        display();

        for (auto& e : enemy) {
            e->attackEntity(getPlayer());
        }

        if (false && (getPFlee() || getPHP() < 1)) {
            setPFlee(false);
            std::cout << "You have been defeated." << std::endl;
            // TODO: monkey bob reference?
            break;
        } else if (enemy.empty()) {
            std::cout << "Victory!" << std::endl;
            break;
        }
    }

    getPlayer()->setSpd(ogspd);
    over = true;
}

void Battle::listEnemies() {

    // Enemies should fit in a 23x7 box
    // Then we add a line on each side
    // Calculate the length of everything
    uint64_t len = enemy.size() * 24 + 1;

    // Print the headers
    std::cout << std::string(len, '-') << std::endl;
    for (const auto& e : enemy) {
        std::cout << '|';
        PU::print(CENTER, e->getName(), 23);
    }
    std::cout << '|' << std::endl;

    // Print the sprites, line by line
    for (int i = 0; i < 5; ++i) {
        for (const auto& e : enemy) {
            std::cout << '|';
            PU::print(CENTER, e->getSprite()[i], 23);
        }
        std::cout << '|' << std::endl;
    }

    // Print the status
    for (const auto& e : enemy) {
        std::cout << '|';
        PU::print(CENTER, e->toString(), 23);
    }
    std::cout << '|' << std::endl;

    std::cout << std::string(len, '-') << std::endl;
}

void Battle::attack() {
    pAttack(enemy[0]);

    this->listEnemies();
    for (size_t i = 0; i < enemy.size(); ++i) {
        if (!enemy[i]->getAlive()) enemy.erase(std::next(enemy.begin(), i));
    }

    //std::erase_if(enemy, [](const std::shared_ptr<Entity>& e){ return !e->getAlive(); });
}

void Battle::escape() { setPFlee(true); }

void Battle::dispatch(int64_t i) {
    switch (i) {
        case 0: this->attack(); break;
        case 1: Battle::escape(); break;
        default: {
            std::cout << "Unexpected state! Things may break!" << std::endl;
        }
    }
}
