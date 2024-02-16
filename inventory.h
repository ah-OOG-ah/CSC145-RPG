#pragma once

#include <cstdint>
#include <string>
#include "item.h"

class Inventory
{
    protected:
    Item* index;
    Item* start;
    Item* end;
    int64_t size = 0;

    public:
    //Constructors
    Inventory();
    Inventory(Item* firstItem);

    //GoToMethods
    void GoToNext();
    void GoToPrev();
    void GoToStart();
    void GoToEnd();
    void GoToPosition(int64_t pos);
    void GoToName(std::string name);

    //Getters
    Item* GetIndex();
    Item* GetStart();
    Item* GetEnd();
    //Changes amount functions
    void ChangeIndexAmnt(int64_t amnt); //Only for index
    void ChangeItemAmnt(int64_t amnt, int64_t pos);
    void ChangeItemAmnt(int64_t amnt, std::string name);

    //Insertion/Deletion functions
    void InsertItem(Item* newItem, int64_t pos);
    void PushBackItem(Item* newItem);
    void RemoveItem(int64_t pos);
    void RemoveItem(std::string name);
    Item* PopBackItem();

    //Made ToString and Print because I want to figure out which one will be more pratical
    std::string ToString();
    void PrintInven(); 
};