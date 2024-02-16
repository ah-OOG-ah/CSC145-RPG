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

    void GoToNext();
    void GoToPrev();
    void GoToStart();
    void GoToEnd();
    void GoToPosition(int64_t pos);
    public:
    /*std::string GetIndexName(); //Made these before the GetIndex function. Might remove
    int64_t GetIndexAmnt();
    std::string GetIndexText();*/
    Item* GetIndex();
    Item* GetStart();
    Item* GetEnd();

    void ChangeIndexAmnt(int64_t amnt); //Only for index
    void ChangeItemAmnt(int64_t amnt, int64_t pos);
    void ChangeItemAmnt(int64_t amnt, std::string name);
    void InsertItem(Item* newItem, int64_t pos);
    void PushBackItem(Item* newItem);
    void RemoveItem(int64_t pos);
    void RemoveItem(std::string name);
    void PopBackItem();
    //Made ToString and Print because I want to figure out which one will be more pratical
    std::string ToString();
    void PrintInven(); 
};