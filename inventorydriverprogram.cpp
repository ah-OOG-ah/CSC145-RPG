/*#include <iostream>
#include "inventory.h"
#include "item.h"
#include "RegularItems.h"
#include <cstdint>
#include <string>

using namespace std;

int main()
{
    AttackItem* rock = new AttackItem("Rock", 4, 10);
    HealItem* potion = new HealItem("Potion", 10, 6);
    AttackItem* spear = new AttackItem("Spear", 1, 20);
    AttackItem* sword = new AttackItem("Sword", 2, 15);
    HealItem* water = new HealItem("Sword", 10, 20);
    Inventory inven(rock);
    cout<<inven.ToString()<<endl;
    inven.PushBackItem(potion);
    inven.PushBackItem(spear);
    cout<<inven.ToString()<<endl;
    inven.PopBackItem();
    inven.PushBackItem(sword);
    inven.PushBackItem(water);
    cout<<inven.ToString()<<endl;
    return 0;
}*/