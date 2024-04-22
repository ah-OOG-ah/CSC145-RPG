    #include "inventory.h"
    #include <cstdint>
    #include <string>
    #include <iostream>

    Inventory::Inventory() { }
    Inventory::Inventory(int64_t itemCap) { numElements = itemCap; }

    int64_t Inventory::GetPos(Item* checkItem)
    {
        for(int i = 0; i < numElements; i++)
        {
            if(start[i]->GetName() == checkItem->GetName())
            {
                return i;
            }
        }
        return -1;
    }
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

    bool Inventory::ReplaceItem(Item* newItem)
    {
        std::cout << "Your INVENTORY is full. Please select item to replace" << std::endl << std::endl;
        std::cout << "Please input the number for the item you want to replace with the "<< newItem->GetName() << std::endl;
        std::cout << "Input a number outside of the range if you do not wish to replace any items" << std::endl;
        PrintItems(1); //Used to print items with numbers by them
        int64_t choice = 0;
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

    void Inventory::RemoveItem(Item* thing, int64_t amnt)
    {
        int64_t pos = this->GetPos(thing);
        if(pos == -1)
        {
            return;
        }
        start[pos]->ChangeAmount(-1 * amnt);
        if(start[pos]->GetAmount() <= 0)
        {
            start[pos] = nullptr;
            usedElements--;
            for(int i = pos; i < numElements - 1; i++)
            {
                start[i] = start[i + 1];
            }
        }
    }

    void Inventory::RemoveItem(int64_t pos, int64_t amnt)
    {
        start[pos]->ChangeAmount(-1 * amnt);
        if(start[pos]->GetAmount() <= 0)
        {
            start[pos] = nullptr;
            usedElements--;
            for(int i = pos; i < numElements - 1; i++)
            {
                start[i] = start[i + 1];
            }
        }
    }

    void Inventory::AddGold(int64_t amnt) { gold+=amnt; }

    int64_t Inventory::GetNumElements() { return numElements; }
    int64_t Inventory::GetUsedElements() { return usedElements; }

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
    void Inventory::PrintItems(int dummy)
    {
        std::cout << "ITEMS" << std::endl;
        for (int i = 0; i < numElements; i++) {

            if (start[i] != nullptr) {
                std::cout<< i + 1 <<". ";
                std::cout << start[i]->GetName() << start[i]->GetAmntText() << start[i]->GetAmount() << "  ";
                std::cout <<"Price "<< start[i]->GetPrice();
                /*if(start[i]->isEquipment())
                {
                    std::cout << start[i]->GetDurab();
                }*/
                std::cout << std::endl;
            }
        }
    }

    void Inventory::PrintInven()
    {
        std::cout << "INVENTORY" << std::endl;
        std::cout << "GOLD" << std::to_string(gold) << std::endl;
        PrintItems();
    }

    void Inventory::PrintInven(int dummy)
    {
        std::cout << "INVENTORY" << std::endl;
        std::cout << "GOLD" << std::to_string(gold) << std::endl;
        PrintItems(1);
        if(dummy == 0)
        {
            SelectItem();
        }
    }

    void Inventory::SelectItem()
    {
        std::cout << "Input number for item you want selected. Enter -1 to exit." << std::endl;
        int64_t choice = 0;
        std::cin>>choice;
        if(choice == -1) { return; }
        if(choice > numElements)
        {
            std::cout << "Please input a valid number" << std::endl;
            this->PrintInven(0);
        }
        else if(choice != -1)
        {
            start[choice]->display();
            this->PrintInven(0);
        }
    }

void Inventory::GarbageCollection()
{
    int64_t removedItems = 0;
    for(int i = 0; i < usedElements; i++)
    {
        if(start[i]->GetAmount() <= 0)
        {
            start[i] = nullptr;
            removedItems++;
        }
    }
    for(int j = 0; j < usedElements; j++)
    {
        if(start[j] == nullptr)
        {
            for(int i = j; i < numElements - 1; i++)
            {
                start[i] = start[i + 1];
            }
        }
    }
    usedElements -= removedItems;
}