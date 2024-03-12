    #include "inventory.h"
    #include <cstdint>
    #include <string>
    #include <iostream>

    Inventory::Inventory() { }
    Inventory::Inventory(Item* first) { start[0] = first; }
    Inventory::Inventory(int64_t itemCap) { numElements = itemCap; }
    Inventory::Inventory(int64_t itemCap, Item* first) { start[0] = first; numElements = itemCap; }

    Item* Inventory::GetElement(int64_t pos)
    {
        return start[pos];
    }
    Item* Inventory::GetElement(std::string name)
    {
        for(int i = 0; i < numElements; i++)
        {
            if((*start)[i].GetName() == name)
            {
                return start[i];
            }
        }
        return nullptr;
    }
    int64_t Inventory::GetGold() { return gold; }
    void Inventory::SetElement(int64_t pos, Item* newItem)
    {
        start[pos] = newItem;
    }
    void Inventory::SetElement(std::string name, Item* newItem)
    {
        int i = 0;
        while((*start)[i].GetName() != name)
        {
            i++;
            if(i >= numElements)
            {
                return;
            }
        }
        start[i] = newItem;
    }

    void Inventory::AddToItem(int64_t amnt,int64_t pos)
    {
        (*start)[pos].ChangeAmount(amnt);
    }
    void Inventory::AddToItem(int64_t amnt, std::string name)
    {
        int i = 0;
        while((*start)[i].GetName() != name)
        {
            i++;
            if(i >= numElements)
            {
                return;
            }
        }
        (*start)[i].ChangeAmount(amnt);
    }

    void Inventory::AddGold(int64_t amnt) { gold+=amnt; }

    std::string Inventory::ToString()
    {
        std::string invenString = "INVENTORY \n";
        invenString += "GOLD" + std::to_string(gold) + "\n";
        for(int i = 0; i < numElements; i++)
        {   
            if(start[i] != nullptr)
            {
            invenString += (*start)[i].GetName();
            invenString += (*start)[i].GetAmntText();
            invenString += (*start)[i].GetAmount();
            invenString += "\n";
            }
        }
        return invenString;
    }
    void Inventory::PrintInven()
    {
        std::cout << "INVENTORY" << std::endl;
        for (int i = 0; i < numElements; i++) {

            if (start[i] != nullptr) {

                std::cout << start[i]->GetName() << start[i]->GetAmntText() << start[i]->GetAmount() << std::endl;
            }
        }
    }