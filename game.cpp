#include "DebugMenu.h"
#include "Player.h"
#include <memory>
#include <random>
#include "game.h"

DebugMenu debugMenu = DebugMenu();
Player player = Player(10);
std::shared_ptr<Scene> scene;

std::shared_ptr<Scene> getScene() {
    return scene;
}

std::shared_ptr<Player> getPlayer() {
    return std::shared_ptr<Player>(&player);
}

typedef std::mt19937 RNG;
RNG rng;
std::random_device sysrng;
std::uniform_int_distribution<int64_t> all_dist;

void initRng() {
    rng.seed(all_dist(sysrng));
}

int64_t getRand() {
    return all_dist(rng);
}

int main() {

    initRng();
    debugMenu.display();
}
