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
    Item** start = new Item*[numElements];

    public:
    bool ReplaceItem(Item*); //function called by AddItem when inventory is full. True if item is replaced, else false
    //Constructors
    Inventory();
    Inventory(int64_t);

    int64_t GetPos(Item*);
    Item* GetItem(int64_t);
    Item* GetItem(std::string);
    int64_t GetGold();
    bool AddItem(Item*); //Adds to amount if Item already is in Inventory. Bool to see if adding was successful
    void RemoveItem(int64_t pos, int64_t amnt = 0); //Used instead of ChangeAmount amount is to be removed. 0 in second integer removes all amount of the item
    void RemoveItem(Item* thing, int64_t amnt = 0); //Used instead of ChangeAmount amount is to be removed. 0 in second integer removes all amount of the item
    void AddGold(int64_t);

    int64_t GetNumElements();
    int64_t GetUsedElements();

    void PrintItems(); //Called by PrintInven
    void PrintItems(int); //Called by functions that need inventory to print with numbers. Integer value is meaningless.
    void PrintInven(); 
    void PrintInven(int dummy = 0);
    void SelectItem(); 
};