#pragma once

#include <cstdint>
#include <string>

class Item
{
    protected:
    std::string name;
    int64_t amount;
    Item* nextItem;
    Item* prevItem;

    public:
    //Constructor
    Item(std::string itemName, int64_t amnt);

    //Getters
    std::string GetName();
    virtual std::string GetAmntText() = 0;
    int64_t GetAmount();
    Item* GetNext();
    Item* GetPrev();
    //Setters
    virtual void ChangeAmount(int64_t addAmnt);
    void SetNext(Item* next);
    void SetPrev(Item* prev);

    //Setters I do not think we need
    void SetName(std::string newName);
};