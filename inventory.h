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

    bool ReplaceItem(Item*); //Private function called by AddItem when inventory is full. True if item is replaced, else false
    bool ReplaceEquip(Equipment*); //Private function called by AddEquip when inventory is full. True if item is replaced, else false
    public:
    //Constructors
    Inventory();
    Inventory(int64_t);

    Item* GetItem(int64_t);
    Item* GetItem(std::string);
    int64_t GetGold();
    Equipment* GetEquip(int64_t);
    Equipment* GetEquip(std::string);
    bool AddItem(Item*); //Adds to amount if Item already is in Inventory. Bool to see if adding was successful
    bool AddEquip(Equipment*); //Bool used to tell if adding was successful
    void PushBack(Item*);
    void SetItem(int64_t, Item*);
    void SetItem(std::string, Item*);
    void AddEquip(int64_t, Equipment*);
    void PushBackEquip(Equipment*); //Used when there is an open spot in inventory for equipment
    
    void AddGold(int64_t);

    //Made ToString and Print because I want to figure out which one will be more pratical
    void PrintInven(); 
};