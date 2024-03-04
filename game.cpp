#include "DebugMenu.h"
#include "Entity.h"
#include "Menu.h"
#include "Player.h"
#include <memory>
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

int main() {

    debugMenu.display();
}
