#include "inventory.h"
#include <cstdint>
#include <string>
#include <iostream>

Inventory::Inventory() = default;
Inventory::Inventory(size_t itemCap) : maxItems(itemCap) { }
Inventory::Inventory(const Inventory& inv) : maxItems(inv.maxItems), numItems(inv.numItems) {
    for (size_t i = 0; i < numItems; ++i) {
        backing.emplace_back(inv.backing[i]->copy());
    }
}
Inventory::Inventory(const std::vector<std::shared_ptr<Item>>& items) : maxItems(items.size()), numItems(maxItems) {
    for (size_t i = 0; i < maxItems; ++i) {
        backing.emplace_back(items[i]->copy());
    }
}
Inventory::Inventory(std::initializer_list<const std::shared_ptr<Item>> il) : maxItems(il.size()), numItems(maxItems) {
    for (const auto& i : il) {
        backing.emplace_back(i->copy());
    }
}

size_t Inventory::GetPos(const std::shared_ptr<Item>& checkItem) {
    for (size_t i = 0; i < maxItems; i++) {
        if (backing[i]->GetName() == checkItem->GetName()) {
            return i;
        }
    }
    return -1;
}

std::shared_ptr<Item> Inventory::GetItem(size_t pos) {
    return backing[pos];
}

std::shared_ptr<Item> Inventory::GetItem(const std::string& name) {
    for (size_t i = 0; i < maxItems; i++) {
        if (backing[i]->GetName() == name) {
            return backing[i];
        }
    }
    return nullptr;
}

int64_t Inventory::GetGold() const { return gold; }

bool Inventory::AddItem(const std::shared_ptr<Item>& newItem) {
    if (newItem == nullptr) return false;

    if (numItems == maxItems) {
        return ReplaceItem(newItem);
    }
    
    for (size_t i = 0; i < maxItems; i++) {
        if (backing[i]->GetName() == newItem->GetName() && backing[i]->isStackable()) {
            backing[i]->ChangeAmount(newItem->GetAmount());
            numItems++;
            return true;
        } else if (backing[i] == nullptr) {
            backing[i] = newItem;
            numItems++;
            return true;
        }
    }
    return false; //Should never be called
}

bool Inventory::ReplaceItem(const std::shared_ptr<Item>& newItem) {

    std::cout << "Your INVENTORY is full. Please select item to replace" << std::endl << std::endl;
    std::cout << "Please input the number for the item you want to replace with the "<< newItem->GetName() << std::endl;
    std::cout << "Input a number outside of the range if you do not wish to replace any items" << std::endl;
    PrintItems(1); //Used to print items with numbers by them
    int64_t choice = 0;
    std::cin >> choice; //Choice will substracted by one to account for the fact that array starts as zero but inventory numbers at 1

    if (choice > 0 && choice <= numItems) {
        std::cout << backing[choice - 1]->GetName() << " was replaced by " << newItem->GetName() << std::endl;
        backing[choice - 1] = newItem;
        return true;
    } else {
        std::cout << newItem->GetName() <<" was not added to inventory" << std::endl;
        return false;
    }
}

void Inventory::RemoveItem(const std::shared_ptr<Item>& thing, int64_t amnt) {
    size_t pos = this->GetPos(thing);
    if (pos >= maxItems) {
        return;
    }
    backing[pos]->ChangeAmount(-1 * amnt);
    if (backing[pos]->GetAmount() <= 0) {
        backing[pos].reset();
        numItems--;
        for (size_t i = pos; i < maxItems - 1; i++) {
            backing[i] = backing[i + 1];
        }
    }
}

void Inventory::RemoveItem(int64_t pos, int64_t amnt) {
    backing[pos]->ChangeAmount(-1 * amnt);
    if (backing[pos]->GetAmount() <= 0) {
        backing[pos].reset();
        numItems--;
        for (size_t i = pos; i < maxItems - 1; i++) {
            backing[i] = backing[i + 1];
        }
    }
}

void Inventory::AddGold(int64_t amnt) { gold += amnt; }

size_t Inventory::GetNumElements() const { return maxItems; }
size_t Inventory::GetUsedElements() const { return numItems; }

void Inventory::PrintItems() {
    std::cout << "ITEMS" << std::endl;
    for (size_t i = 0; i < maxItems; i++) {
        if (backing[i] != nullptr) {
            std::cout << backing[i]->GetName() << backing[i]->GetAmntText() << backing[i]->GetAmount() << "  ";
            std::cout << "Price " << backing[i]->GetPrice() << std::endl;
        }
    }
}

void Inventory::PrintItems(int dummy) {
    std::cout << "ITEMS" << std::endl;
    for (size_t i = 0; i < maxItems; i++) {
        if (backing[i] != nullptr) {
            std::cout<< i + 1 <<". ";
            std::cout << backing[i]->GetName() << backing[i]->GetAmntText() << backing[i]->GetAmount() << "  ";
            std::cout << "Price " << backing[i]->GetPrice();
            /*if(start[i]->isEquipment())
            {
                std::cout << start[i]->GetDurab();
            }*/
            std::cout << std::endl;
        }
    }
}

void Inventory::PrintInven() {
    std::cout << "INVENTORY" << std::endl;
    std::cout << "GOLD" << std::to_string(gold) << std::endl;
    PrintItems();
}

void Inventory::PrintInven(int dummy) {
    std::cout << "INVENTORY" << std::endl;
    std::cout << "GOLD" << std::to_string(gold) << std::endl;
    PrintItems(1);
    if (dummy == 0) {
        SelectItem();
    }
}

void Inventory::SelectItem() {
    std::cout << "Input number for item you want selected. Enter -1 to exit." << std::endl;
    int64_t choice = 0;
    std::cin>>choice;
    if (choice == -1) { return; }
    if (choice > maxItems) {
        std::cout << "Please input a valid number" << std::endl;
        this->PrintInven(0);
    } else if (choice != -1) {
        backing[choice]->display();
        this->PrintInven(0);
    }
}

void Inventory::GarbageCollection() {
int64_t removedItems = 0;
for (size_t i = 0; i < numItems; i++) {
    if (backing[i]->GetAmount() <= 0) {
        backing[i] = nullptr;
        removedItems++;
    }
}
for (size_t j = 0; j < numItems; j++) {
    if (backing[j] == nullptr) {
        for (size_t i = j; i < maxItems - 1; i++) {
            backing[i] = backing[i + 1];
        }
    }
}
    numItems -= removedItems;
}
