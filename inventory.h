#pragma once

#include <cstdint>
#include <string>
#include "item.h"
#include "RegularItems.h"

class Inventory
{
    protected:
    int numElements = 30;
    Item** start = new Item*[numElements];

    public:
    //Constructors
    Inventory();
    Inventory(Item*);

    Item* GetElement(int64_t);
    Item* GetElement(std::string);
    void SetElement(int64_t, Item*);
    void SetElement(std::string, Item*);

    void AddToItem(int64_t,int64_t);
    void AddToItem(int64_t, std::string);

    //Made ToString and Print because I want to figure out which one will be more pratical
    std::string ToString();
    void PrintInven(); 
};