#include "Item.h"
#include "RegularItems.h"

int maxSlots = 30;
Item** backing = new Item*[maxSlots];


int main (){

    backing[0] = new AttackItem("Name", 1, 1);
    backing[1] = new AttackItem("name", 1, 1);
}
