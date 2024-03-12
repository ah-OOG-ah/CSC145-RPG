#pragma once

#include <cstdint>
#include <string>
#include "item.h"
#include "RegularItems.h"

class Inventory
{
    protected:
    int64_t gold = 0;
    int numElements = 30;
    Item** start = new Item*[numElements];

    public:
    //Constructors
    Inventory();
    Inventory(Item*);
    Inventory(int64_t);
    Inventory(int64_t, Item*);

    Item* GetElement(int64_t);
    Item* GetElement(std::string);
    int64_t GetGold();
    void SetElement(int64_t, Item*);
    void SetElement(std::string, Item*);

    void AddToItem(int64_t,int64_t);
    void AddToItem(int64_t, std::string);
    void AddGold(int64_t);

    //Made ToString and Print because I want to figure out which one will be more pratical
    std::string ToString();
    void PrintInven(); 
};