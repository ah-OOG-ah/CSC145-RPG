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
#include <iostream>


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
    Inventory inven(rock);
    std::cout<<inven.ToString()<<std::endl;
    inven.SetElement(1, potion);
    inven.SetElement(2, spear);
    std::cout<<inven.ToString()<<std::endl;
    inven.SetElement(2, nullptr);
    inven.SetElement(2, sword);
    inven.SetElement(3, water);
    std::cout<<inven.ToString()<<std::endl;
   //debugMenu.display();
}
