#include "DebugMenu.h"
#include "Entity.h"
#include "Player.h"
#include <memory>
#include <random>
#include "game.h"
#include "scene/Tower.h"


DebugMenu debugMenu = DebugMenu();
Player player = Player(10);
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
    return std::shared_ptr<Player>(&player);
}

int main() {
    initRng();

    Tower tower("The Tower of Ycauiw Ccc");
    tower.run();

    debugMenu.display();
}
