#include "Battle.h"
#include "BattleMenu.h"
#include "Enemy.h"
#include "Scene.h"
#include "game.h"
#include <string>
#include <vector>

Battle::Battle(std::string name) : Scene(name), battleMenu(BattleMenu()) {

    this->player = getPlayer();
    this->enemy = std::vector<Enemy>();
    this->enemy.push_back(Enemy(10));
}

/*
First, the player should get the Battle menu
Then, the player acts
Then, the enemy acts
Then, the battle checks if a side is dead; repeat
*/
void Battle::run() {

    while (true) {

        this->battleMenu.display();

        if (this->player->getFleeing() || this->player->getHp() < 1 || this->enemy.empty()) {
            break;
        }
    }
}
