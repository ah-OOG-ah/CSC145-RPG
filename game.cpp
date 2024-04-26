#include "DebugMenu.h"
#include "entity/Entity.h"
#include "entity/Player.h"
#include <memory>
#include <random>
#include <iostream>
#include <utility>
#include "game.h"
#include "scene/Tower.h"


DebugMenu debugMenu = DebugMenu();
auto player = std::make_shared<Player>(10);
std::shared_ptr<Scene> scene;

typedef std::mt19937 RNG;
RNG rng; // NOLINT(*-msc51-cpp)
std::random_device sysrng;
std::uniform_int_distribution<uint64_t> udist;
std::uniform_int_distribution<int64_t> dist;

void initRng() {
    rng.seed(udist(sysrng));
}

uint64_t randUint() { return udist(rng); }
int64_t randInt() { return dist(rng); }
bool randBool() { return randUint() % 2 == 0; }

std::shared_ptr<Scene> getScene() {
    return scene;
}

std::shared_ptr<Player> getPlayer() {
    return player;
}
int64_t getPHP() { return player->getCurrentHp(); }
bool getPFlee() { return player->getFleeing(); }

void setPFlee(bool b) { player->setFleeing(b); }

void pAttack(const std::shared_ptr<Entity>& e) { player->attackEntity(e); }
void pDisplay() {
    std::cout << player->toString() << std::endl;
}

void saveGame() {
    std::cout << "Not imeplemented yet." << std::endl;
}

int main() {
    initRng();

    Tower tower("The Tower of Ycauiw Ccc");
    tower.run();

    debugMenu.display();
}
