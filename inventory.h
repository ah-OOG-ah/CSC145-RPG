#pragma once

#include <cstdint>
#include <string>
#include "item.h"
#include "RegularItems.h"
#include "Equipment.h"

class Inventory
{
    protected:
    int64_t gold = 0;
    int numElements = 30;
    int usedElements = 0;
    int numEquips = 10;
    int usedEquips = 0;
    Item** start = new Item*[numElements];
    Equipment** tools = new Equipment*[numEquips];

    public:
    //Constructors
    Inventory();
    Inventory(Item*);
    Inventory(int64_t);
    Inventory(int64_t, Item*);

    Item* GetItem(int64_t);
    Item* GetItem(std::string);
    int64_t GetGold();
    Equipment* GetEquip(int64_t);
    Equipment* GetEquip(std::string);
    void PushBack(Item*);
    void SetItem(int64_t, Item*);
    void SetItem(std::string, Item*);
    void AddEquip(int64_t, Equipment*);
    void PushBackEquip(Equipment*); //Used when there is an open spot in inventory for equipment
    

    void AddToItem(int64_t,int64_t);
    void AddToItem(int64_t, std::string);
    void AddGold(int64_t);

    //Made ToString and Print because I want to figure out which one will be more pratical
    void PrintInven(); 
};