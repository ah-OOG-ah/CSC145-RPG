    #include "inventory.h"
    #include <cstdint>
    #include <string>
    #include <iostream>

    Inventory::Inventory() { }
    Inventory::Inventory(Item* first) { start[0] = first; }
 
    Item* Inventory::GetElement(int64_t pos)
    {
        return start[pos];
    }
    Item* Inventory::GetElement(std::string name)
    {
        for(int i = 0; i < numElements; i++)
        {
            if(start[i].GetName() == name)
            {
                return start[i];
            }
        }
        return nullptr;
    }
    void Inventory::SetElement(int64_t pos, Item* newItem)
    {
        start[pos] = newItem;
    }
    void Inventory::SetElement(std::string name, Item* newItem)
    {
        int i = 0;
        while(start[i].GetName() != name)
        {
            i++;
            if(num >= numElements)
            {
                return;
            }
        }
        start[i] = newItem;
    }

    void Inventory::AddToItem(int64_t amnt,int64_t pos)
    {
        start[pos].ChangeAmount(amnt);
    }
    void Inventory::AddToItem(int64_t amnt, std::string name)
    {
        int i = 0;
        while(start[i].GetName() != name)
        {
            i++;
            if(num >= numElements)
            {
                return;
            }
        }
        start[i].ChangeAmount(amnt);
    }


    std::string Inventory::ToString();
    void Inventory::PrintInven(); 