#pragma once

#include <cstdint>
#include <string>

class Item
{
    protected:
    std::string itemName;
    int64_t amount;
    Item* nextItem;
    Item* prevItem;
    int64_t amountTitle; //Will determine if item say amount, uses, or nothing when going through inven using a switch statement
    //Was going to use an enum but not sure what to do with GetAmntTitle()

    public:
    //Constructor
    Item(std::string name, int64_t amnt, int64_t amountDetermine);

    //Getters
    std::string GetName();
    int64_t GetAmount();
    Item* GetNext();
    Item* GetPrev();
    int64_t GetAmntTitle();
    //Setters
    void ChangeAmount(int64_t addAmnt);
    void SetNext(Item* next);
    void SetPrev(Item* prev);

    //Setters I do not think we need
    void SetName(std::string newName);
    void SetAmountTitle(int64_t newTitle);
};