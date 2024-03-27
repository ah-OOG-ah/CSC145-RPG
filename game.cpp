#include "Menu/DebugMenu.h"
#include "Player.h"
#include <memory>
#include <random>
#include <iostream>
#include "game.h"
#include "Tower.h"
#include "Menu/StartMenu.h"

DebugMenu debugMenu = DebugMenu();
StartMenu startMenu = StartMenu();
Player player = Player(10);
std::shared_ptr<Scene> scene;

typedef std::mt19937 RNG;
RNG rng;
std::random_device sysrng;
std::uniform_int_distribution<int64_t> all_dist;

int64_t level = 0;

Tower theTower;

std::shared_ptr<Scene> getScene() { return scene; }

std::shared_ptr<Player> getPlayer() { return std::shared_ptr<Player>(&player); }

int64_t getRand() { return all_dist(rng); }

int64_t getLevel() { return level; }

Tower getTower() { return theTower; }

void printExit() {

    std::cout << "ICRU" << std::endl;
}

void newFloor() {

    theTower.pushFloor();
}

int main() {

    rng.seed(all_dist(sysrng));
    startMenu.display();
    //debugMenu.display();
}
