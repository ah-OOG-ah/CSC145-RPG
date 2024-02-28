#include "item.h"

#include <cstdint>
#include <string>

    Item::Item(std::string itemName)
    { 
        name = itemName;
    }
    Item::Item(std::string itemName, int64_t amnt)
    {
        name = itemName;
        amount = amnt;
    }

    std::string Item::GetName() { return name; }
    int64_t Item::GetAmount() { return amount; }


    void Item::ChangeAmount(int64_t addAmnt) { amount += addAmnt; }

    void Item::SetName(std::string newName) { name = newName; }
