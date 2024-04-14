#include "DebugMenu.h"
#include "Entity.h"
#include "Menu.h"
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
std::uniform_int_distribution<int64_t> all_dist;

void initRng() {
    rng.seed(all_dist(sysrng));
}

int64_t getRand() {
    return all_dist(rng);
}

std::shared_ptr<Scene> getScene() {
    return scene;
}

std::shared_ptr<Player> getPlayer() {
    return std::shared_ptr<Player>(&player);
}

int main() {
    initRng();

    Tower tower(std::string());

    debugMenu.display();
}
