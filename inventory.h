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
    void RemoveItem(int64_t pos, int64_t amnt = 0); //Used instead of ChangeAmount amount is to be removed. 0 in second integer removes all amount of the item
    void RemoveEquipment(int64_t pos);
    void AddGold(int64_t);

    int64_t GetNumElements();
    int64_t GetNumEquips();
    int64_t GetUsedElements();
    int64_t GetUsedEquips();

    void PrintItems(); //Called by PrintInven
    void PrintEquip(); //Called by PrintInven
    void PrintItems(int); //Called by functions that need inventory to print with numbers. Integer value is meaningless.
    void PrintEquip(int); //Called by functions that need inventory to print with numbers. Integer value is meaningless.
    void PrintInven(); 

};