#include "Battle.h"
#include "Menu.h"
#include "Scene.h"
#include <string>

Battle::Battle(std::string name, Menu menu) : Scene(name), battleMenu(menu) {}

/*
First, the player should get the Battle menu
Then, the player acts
Then, the enemy acts
Then, the battle checks if a side is dead; repeat
*/
void Battle::run() {

    do {

        
    } while (player->getHp() > 0 && !this->enemy.empty());
}
