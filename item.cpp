#include "item.h"

#include <cstdint>
#include <string>

    Item::Item(std::string itemName, int64_t amnt)
    {
        name = itemName;
        amount = amnt;
    }

    std::string Item::GetName() { return name; }
    int64_t Item::GetAmount() { return amount; }
    Item* Item::GetNext() { return nextItem; }
    Item* Item::GetPrev() { return prevItem; }


    void Item::ChangeAmount(int64_t addAmnt) { amount += addAmnt; }
    void Item::SetNext(Item* next) { nextItem = next; }
    void Item::SetPrev(Item* prev) { prevItem = prev; }

    void Item::SetName(std::string newName) { name = newName; }
