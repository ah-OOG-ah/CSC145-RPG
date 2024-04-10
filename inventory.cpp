    #include "inventory.h"
    #include <cstdint>
    #include <string>
    #include <iostream>

    Inventory::Inventory() { }
    Inventory::Inventory(int64_t itemCap) { numElements = itemCap; }

    Item* Inventory::GetItem(int64_t pos)
    {
        return start[pos];
    }
    Item* Inventory::GetItem(std::string name)
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
    Equipment* Inventory::GetEquip(int64_t pos) { return tools[pos]; }
    Equipment* Inventory::GetEquip(std::string name){
        for(int i = 0; i < numEquips; i++)
        {
            if((*tools)[i].GetName() == name)
            {
                return tools[i];
            }
        }
        return nullptr;
    }

    bool Inventory::ReplaceItem(Item* newItem)
    {
        
    }

    bool Inventory::AddItem(Item* newItem)
    {
        if(newItem == nullptr) { return false; }
        if(usedElements == numElements)
        {
            return ReplaceItem(newItem);
        }
        for(int i = 0; i < numElements; i++)
        {
            if(start[i]->GetName() == newItem->GetName())
            {
                start[i]->ChangeAmount(newItem->GetAmount());
                usedElements++;
                return true;
            }
            else if(start[i] == nullptr)
            {
                start[i] = newItem;
                usedElements++;
                return true;
            }
        }
        return false; //Should never be called
    }

    void Inventory::SetItem(int64_t pos, Item* newItem)
    {
        start[pos] = newItem;
        if(newItem != nullptr) { usedElements++; } //Used to handle case when someone tries to use set item to remove an item
        else{ usedElements--; }
    }
    void Inventory::SetItem(std::string name, Item* newItem)
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
        if(newItem != nullptr) { usedElements++; } //Used to handle case when someone tries to use set item to remove an item
        else{ usedElements--; }
    }

    void Inventory::AddEquip(int64_t pos, Equipment* tool)
    {
        if(pos < 0 || pos > numEquips)
        {
            return;
        }
        tools[pos] = tool;
        if(tool != nullptr) { usedEquips++; } //Used to handle case when someone tries to use set item to remove an item
        else{ usedEquips--; }
    }

    void Inventory::PushBackEquip(Equipment* newTool)
    {
        if(usedEquips = numEquips) { return; }
        tools[usedEquips] = newTool;
        usedEquips++;
    }

    void Inventory::PushBack(Item* newItem)
    {
        if(usedElements = numElements) { return; }
        start[usedElements] = newItem;
        usedElements++;
    }

    void Inventory::AddGold(int64_t amnt) { gold+=amnt; }

    void Inventory::PrintInven()
    {
        std::cout << "INVENTORY" << std::endl;
        std::cout << "GOLD" << std::to_string(gold) << std::endl;
        std::cout << "EQUIPMENT" << std::endl;
        for(int i = 0; i < numEquips; i++)
        {
            if(tools[i] != nullptr)
            {
                std::cout << tools[i]->GetName() << "Durability: " << tools[i]->GetDurab() << "  ";
                std::cout << "Price: " << tools[i]->GetPrice() << std::endl; 
            }
        }
        std::cout << "ITEMS" << std::endl;
        for (int i = 0; i < numElements; i++) {

            if (start[i] != nullptr) {

                std::cout << start[i]->GetName() << start[i]->GetAmntText() << start[i]->GetAmount() << "  ";
                std::cout <<"Price "<< start[i]->GetPrice() << std::endl;
            }
        }
    }