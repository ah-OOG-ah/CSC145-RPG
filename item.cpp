#include "item.h"

#include <cstdint>
#include <string>

    Item::Item(std::string name, int64_t amnt, int64_t amountDetermine)
    {
        itemName = name;
        amount = amnt;
        amount = amountDetermine;
    }

    std::string Item::GetName() { return itemName; }
    int64_t Item::GetAmount() { return amount; }
    Item* Item::GetNext() { return nextItem; }
    Item* Item::GetPrev() { return prevItem; }
    int64_t Item::GetAmntTitle() { return amountTitle;}

    void Item::ChangeAmount(int64_t addAmnt) { amount += addAmnt; }
    void Item::SetNext(Item* next) { nextItem = next; }
    void Item::SetPrev(Item* prev) { prevItem = prev; }

    void Item::SetName(std::string newName) { itemName = newName; }
    void Item::SetAmountTitle(int64_t newTitle) { amountTitle = newTitle; }