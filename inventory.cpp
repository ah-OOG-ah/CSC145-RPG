    #include "inventory.h"
    #include <cstdint>
    #include <string>
    #include <iostream>

    Inventory::Inventory() { }
    Inventory::Inventory(Item* first) { start[0] = first; }
    Inventory::Inventory(int64_t itemCap) { numElements = itemCap; }
    Inventory::Inventory(int64_t itemCap, Item* first) { start[0] = first; numElements = itemCap; }

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


    void Inventory::SetItem(int64_t pos, Item* newItem)
    {
        start[pos] = newItem;
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
    }

    void Inventory::AddEquip(int64_t pos, Equipment* tool)
    {
        if(pos < 0 || pos > numEquips)
        {
            return;
        }
        tools[pos] = tool;
    }

    void Inventory::PushBackEquip(Equipment* newTool)
    {
        int i = 0;
        do
        {
            i++;
        } while (tools[i] != nullptr);
        tools[i] = newTool;
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

    void Inventory::PushBack(Item* newItem)
    {
        int i = 0;
        do
        {
            i++;
        } while (start[i] != nullptr);
        start[i] = newItem;
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
                std::cout << tools[i]->GetName() << std::endl;
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