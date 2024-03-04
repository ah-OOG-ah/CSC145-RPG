#include "DebugMenu.h"
#include "Entity.h"
#include "Menu.h"
#include "Player.h"
#include <memory>
#include "game.h"
#include "inventory.h"
#include "item.h"
#include "RegularItems.h"
#include <cstdint>
#include <string>


DebugMenu debugMenu = DebugMenu();
Player player = Player(10);

std::shared_ptr<Player> getPlayer() {
    return std::shared_ptr<Player>(&player);
}

int main() {
    AttackItem* rock = new AttackItem("Rock", 4, 10);
    HealItem* potion = new HealItem("Potion", 10, 6);
    AttackItem* spear = new AttackItem("Spear", 1, 20);
    AttackItem* sword = new AttackItem("Sword", 2, 15);
    HealItem* water = new HealItem("Sword", 10, 20);
    Inventory myInven(5, rock);
    myInven.PrintInven();
    myInven.SetElement(1, potion);
    myInven.PrintInven();
    myInven.SetElement(1, spear);
    myInven.SetElement(2, sword);
    myInven.PrintInven();
    myInven.SetElement(4, water);
    myInven.PrintInven();
    //debugMenu.display();
    return 0;
}
