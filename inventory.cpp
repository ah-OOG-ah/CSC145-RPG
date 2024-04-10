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
        std::cout << "Your INVENTORY is full. Please select item to replace" << std::endl << std::endl;
        std::cout << "Please input the number for the item you want to replace with the "<< newItem->GetName() << std::endl;
        std::cout << "Input a number outside of the range such as 0 if you do not wish to replace any items" << std::endl;
        PrintItems(1); //Used to print items with numbers by them
        int choice = 0;
        std::cin>>choice; //Choice will substracted by one to account for the fact that array starts as zero but inventory numbers at 1
        if(choice > 0 && choice <= usedElements)
        {
            std::cout << start[choice - 1]->GetName() << " was replaced by " << newItem->GetName() << std::endl;
            start[choice - 1] = newItem;
            return true;
        }
        else
        {
            std::cout << newItem->GetName() <<" was not added to inventory" << std::endl;
            return false;
        }
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
            if(start[i]->GetName() == newItem->GetName() && start[i]->isStackable())
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

    bool Inventory::ReplaceEquip(Equipment* newEquip)
    {
        std::cout << "Your INVENTORY is full. Please select equipment to replace" << std::endl << std::endl;
        std::cout << "Please input the number for the equipment you want to replace with the "<< newEquip->GetName() << std::endl;
        std::cout << "Input a number outside of the range such as 0 if you do not wish to replace any items" << std::endl;
        PrintEquip(1); //Used to print items with numbers by them
        int choice = 0;
        std::cin>>choice; //Choice will substracted by one to account for the fact that array starts as zero but inventory numbers at 1
        if(choice > 0 && choice <= usedEquips)
        {
            std::cout << tools[choice - 1]->GetName() << " was replaced by " << newEquip->GetName() << std::endl;
            tools[choice - 1] = newEquip;
            return true;
        }
        else
        {
            std::cout << newEquip->GetName() <<" was not added to inventory" << std::endl;
            return false;
        }
    }

    bool Inventory::AddEquip(Equipment* tool)
    {
        if(tool == nullptr) { return false; }
        if(usedEquips == numEquips)
        {
            return ReplaceEquip(tool);
        }
        for(int i = 0; i < numEquips; i++)
        {
            if(tools[i] == nullptr)
            {
                tools[i] = tool;
                usedElements++;
                return true;
            }
        }
        return false; //Should never be called
    }

    void Inventory::AddGold(int64_t amnt) { gold+=amnt; }

    void Inventory::PrintItems()
    {
        std::cout << "ITEMS" << std::endl;
        for (int i = 0; i < numElements; i++) {

            if (start[i] != nullptr) {
                std::cout << start[i]->GetName() << start[i]->GetAmntText() << start[i]->GetAmount() << "  ";
                std::cout <<"Price "<< start[i]->GetPrice() << std::endl;
            }
        }
    }
    void Inventory::PrintEquip()
    {
        std::cout << "EQUIPMENT" << std::endl;
        for(int i = 0; i < numEquips; i++)
        {
            if(tools[i] != nullptr)
            {
                std::cout << tools[i]->GetName() << "Durability: " << tools[i]->GetDurab() << "  ";
                std::cout << "Price: " << tools[i]->GetPrice() << std::endl; 
            }
        }
    }
    void Inventory::PrintItems(int dummy)
    {
        std::cout << "ITEMS" << std::endl;
        for (int i = 0; i < numElements; i++) {

            if (start[i] != nullptr) {
                std::cout<< i + 1 <<". ";
                std::cout << start[i]->GetName() << start[i]->GetAmntText() << start[i]->GetAmount() << "  ";
                std::cout <<"Price "<< start[i]->GetPrice() << std::endl;
            }
        }
    }
    void Inventory::PrintEquip(int dummy)
    {
        std::cout << "EQUIPMENT" << std::endl;
        for(int i = 0; i < numEquips; i++)
        {
            if(tools[i] != nullptr)
            {
                std::cout<< i + 1 <<". ";
                std::cout << tools[i]->GetName() << "Durability: " << tools[i]->GetDurab() << "  ";
                std::cout << "Price: " << tools[i]->GetPrice() << std::endl; 
            }
        }
    }

    void Inventory::PrintInven()
    {
        std::cout << "INVENTORY" << std::endl;
        std::cout << "GOLD" << std::to_string(gold) << std::endl;
        PrintEquip();
        PrintItems();
    }

/*
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
*/