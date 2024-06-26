#include "DebugMenu.h"
#include "entity/Entity.h"
#include "entity/Player.h"
#include <memory>
#include <random>
#include <iostream>
#include "game.h"
#include "scene/Tower.h"
#include "PU.h"


DebugMenu debugMenu = DebugMenu();
auto player = std::make_shared<Player>(100000);
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

bool manageInventory(const std::vector<std::shared_ptr<Entity>>& enemies, bool& exit) {
    std::cout << "Press 0 to exit." << std::endl;
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

    if (i == 0) {
        exit = true;
        return false;
    }

    auto item = player->inventory[i - 1];
    if (item->GetType() == ATTACK) {
        if (enemies.empty()) {
            std::cout << "No enemies to target!" << std::endl;
            return false;
        }

        player->inventory.changeWeight(-player->inventory[i - 1]->getWeight());
        player->inventory[i - 1]->use(player, { player }, enemies);
        player->inventory.changeWeight(player->inventory[i - 1]->getWeight());
        return true;
    }

    // Equip a weapon or armor
    if (item->GetType() == WEAPON) {
        auto tmp = player->currentWeapon;
        player->currentWeapon.reset(dynamic_cast<Weapon*>(player->inventory.RemoveItem(i - 1).release()));
        if (tmp->isReal()) player->inventory.AddItem(tmp);
        return true;
    }

    if (item->GetType() == ARMOR) {
        auto tmp = player->armor.set(dynamic_cast<Armor*>(player->inventory.RemoveItem(i - 1).release()));
        if (tmp->isReal()) player->inventory.AddItem(tmp);
        return true;
    }

    // Heals or statuses get applied unconditionally
    if (item->GetType() == HEAL || item->GetType() == STATUS) {
        player->inventory.changeWeight(-player->inventory[i - 1]->getWeight());
        player->inventory[i - 1]->use(player, { player }, enemies);
        player->inventory.changeWeight(player->inventory[i - 1]->getWeight());
        return true;
    }

    // Whar?
    std::cout << "Unexpected item type ";
    switch (item->GetType()) {
        case NONE: std::cout << "NONE"; break;
        case ATTACK: std::cout << "ATTACK"; break;
        case HEAL: std::cout << "HEAL"; break;
        case STATUS: std::cout << "STATUS"; break;
        case WEAPON: std::cout << "WEAPON"; break;
        case ARMOR: std::cout << "ARMOR"; break;
    }
    std::cout << ", doing nothing" << std::endl;
    return false;
}

int main() {
    initRng();

    player->inventory.AddGold(1000);

    Tower tower("The Tower of Ycauiw Ccc");
    tower.run();

    std::cout << "You leave the tower, although you'll never be able to leave the nightmares..." << std::endl;
    std::array<std::string, 5> face = {
            "HAIL [REDACTED]",
            "{(|)..(|)}",
            "    --    ",
            "          ",
            "          "
    };
    for (const auto& line : face) {
        PU::print(CENTER, line, 30);
        std::cout << std::endl;
    }
}
