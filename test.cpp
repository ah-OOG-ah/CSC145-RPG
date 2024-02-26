#include "item.h"
#include "RegularItems.h"

int numElements = 30;
Item** start = new Item*[numElements];


int main (){

    start[0] = new AttackItem("Name", 1, 1);
    start[1] = new AttackItem("name", 1, 1);
}
