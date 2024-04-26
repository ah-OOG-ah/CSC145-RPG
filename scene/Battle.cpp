#include "Battle.h"
#include "Enemy.h"
#include "scene/Scene.h"
#include "game.h"
#include "enemytiers.h"
#include <string>
#include <utility>
#include <vector>
#include <iostream>


Battle::Battle(std::string name, int64_t nice) : Scene(std::move(name)), Menu(std::vector<std::string>({
    "Attack",
    "Escape"
})) {
    this->enemy = std::vector<Enemy>();

    auto numEnemy = randUint() % nice + 5;
    auto src = ETiers::get(nice);

    for (uint64_t i = 0; i < numEnemy; ++i) {
        this->enemy.emplace_back(src[randUint() % src.size()]);
    }
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

    // Load turn queue
    for (auto & e : enemy) { turnOrder.emplace_back(&e); }
    turnOrder.emplace_back(getPlayer());
    auto ogspd = getPlayer()->getSpd();

    while (true) {


        std::cout << "\nYou see the enemy: " << std::endl;
        this->listEnemies();

        std::sort(turnOrder.begin(), turnOrder.end());

        for (const auto& e : turnOrder) {
            if (e == getPlayer()) {
                display();
            } else {
                e->attackEntity(getPlayer());
            }

            e->changeSpd(-30);
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

    turnOrder.clear();
    getPlayer()->setSpd(ogspd);
    over = true;
}

void Battle::listEnemies() {
    for (const auto& e : enemy) {
        std::cout << e.toString() << std::endl;
    }
}

void Battle::attack() {

    pAttack(turnOrder[0]);
    this->listEnemies();
    std::erase_if(turnOrder, [](const std::shared_ptr<Entity>& e){ return !e->getAlive(); });
    std::erase_if(enemy, [](const Enemy& e){ return !e.getAlive(); });
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
