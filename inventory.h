#pragma once

#include <cstdint>
#include <string>
#include "item.h"

class Inventory
{
    protected:
    Item* index;
    Item* start;

    void GoToNext();
    void GoToPrev();
    void GoToStart();
    void GoToEnd();

    public:
    std::string GetIndexName();
    int64_t GetIndexAmnt();
    std::string GetIndexText();

    void ChangeItemAmnt(int64_t amnt); //Only for index
    void ChangeItemAmnt(int64_t amnt, int64_t pos);
    void ChangeItemAmnt(int64_t amnt, std::string name);
    void InsertItem(Item* newItem, int64_t pos);
    void RemoveItem(int64_t pos);
    void RemoveItem(std::string name);
    //Made ToString and Print because I want to figure out which one will be more pratical
    std::string ToString();
    void PrintInven(); 
};