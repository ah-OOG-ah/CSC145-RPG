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

std::shared_ptr<Player> getPlayer() {
    return player;
}
double getPHP() { return player->getCurrentHp(); }
bool getPFlee() { return player->getFleeing(); }

void setPFlee(bool b) { player->setFleeing(b); }

void pAttack(const std::shared_ptr<Entity>& e) { player->attackEntity(e); }
void pDisplay() {
    std::cout << player->toString() << std::endl;
}

void saveGame() {
    std::cout << "Not imeplemented yet." << std::endl;
}

bool manageInventory(const std::vector<std::shared_ptr<Entity>>& enemies) {
    player->inventory.print(true);

    std::string choice;
    size_t i = -1;
    while (true) {
        std::getline(std::cin, choice);

        try {
            i = std::stoi(choice);
        } catch (std::invalid_argument&) {
            std::cout << "Not a number" << std::endl;
            continue;
        }

        if (i > player->inventory.getUsedSlots()) {
            std::cout << "Invalid index" << std::endl;
            continue;
        }
        break;
    }

    auto item = player->inventory[i - 1];
    if (item->GetType() == ATTACK && enemies.empty()) {
        std::cout << "No enemies to target!" << std::endl;
        return false;
    }

    if (item->GetType() == WEAPON) {
        auto tmp = player->currentWeapon;
        //player->currentWeapon.reset(dynamic_cast<Weapon*>(player->inventory.RemoveItem(i - 1)));
    }
}

int main() {
    initRng();

    Tower tower("The Tower of Ycauiw Ccc");
    tower.run();

    debugMenu.display();
}
