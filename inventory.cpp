#include "inventory.h"
#include <cstdint>
#include <string>
#include <iostream>

Inventory::Inventory() = default;
Inventory::Inventory(size_t itemCap) : numElements(itemCap) { }
Inventory::Inventory(const Inventory& inv) : numElements(inv.numElements), usedElements(inv.usedElements) {
    for (size_t i = 0; i < usedElements; ++i) {
        start.emplace_back(inv.start[i]->copy());
    }
}
Inventory::Inventory(const std::vector<std::shared_ptr<Item>>& items) : numElements(items.size()), usedElements(numElements) {
    for (size_t i = 0; i < numElements; ++i) {
        start.emplace_back(items[i]->copy());
    }
}
Inventory::Inventory(std::initializer_list<const std::shared_ptr<Item>> il) : numElements(il.size()), usedElements(numElements) {
    for (const auto& i : il) {
        start.emplace_back(i->copy());
    }
}

size_t Inventory::GetPos(const std::shared_ptr<Item>& checkItem) {
    for (size_t i = 0; i < numElements; i++) {
        if (start[i]->GetName() == checkItem->GetName()) {
            return i;
        }
    }
    return -1;
}

std::shared_ptr<Item> Inventory::GetItem(size_t pos) {
    return start[pos];
}

std::shared_ptr<Item> Inventory::GetItem(const std::string& name) {
    for (size_t i = 0; i < numElements; i++) {
        if (start[i]->GetName() == name) {
            return start[i];
        }
    }
    return nullptr;
}

int64_t Inventory::GetGold() const { return gold; }

bool Inventory::AddItem(const std::shared_ptr<Item>& newItem) {
    if (newItem == nullptr) return false;

    if (usedElements == numElements) {
        return ReplaceItem(newItem);
    }
    for (size_t i = 0; i < numElements; i++) {
        if (start[i]->GetName() == newItem->GetName() && start[i]->isStackable()) {
            start[i]->ChangeAmount(newItem->GetAmount());
            usedElements++;
            return true;
        } else if (start[i] == nullptr) {
            start[i] = newItem;
            usedElements++;
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

    if (choice > 0 && choice <= usedElements) {
        std::cout << start[choice - 1]->GetName() << " was replaced by " << newItem->GetName() << std::endl;
        start[choice - 1] = newItem;
        return true;
    } else {
        std::cout << newItem->GetName() <<" was not added to inventory" << std::endl;
        return false;
    }
}

void Inventory::RemoveItem(const std::shared_ptr<Item>& thing, int64_t amnt) {
    size_t pos = this->GetPos(thing);
    if (pos >= numElements) {
        return;
    }
    start[pos]->ChangeAmount(-1 * amnt);
    if (start[pos]->GetAmount() <= 0) {
        start[pos].reset();
        usedElements--;
        for (size_t i = pos; i < numElements - 1; i++) {
            start[i] = start[i + 1];
        }
    }
}

void Inventory::RemoveItem(int64_t pos, int64_t amnt) {
    start[pos]->ChangeAmount(-1 * amnt);
    if (start[pos]->GetAmount() <= 0) {
        start[pos].reset();
        usedElements--;
        for (size_t i = pos; i < numElements - 1; i++) {
            start[i] = start[i + 1];
        }
    }
}

void Inventory::AddGold(int64_t amnt) { gold += amnt; }

size_t Inventory::GetNumElements() const { return numElements; }
size_t Inventory::GetUsedElements() const { return usedElements; }

void Inventory::PrintItems() {
    std::cout << "ITEMS" << std::endl;
    for (size_t i = 0; i < numElements; i++) {
        if (start[i] != nullptr) {
            std::cout << start[i]->GetName() << start[i]->GetAmntText() << start[i]->GetAmount() << "  ";
            std::cout <<"Price "<< start[i]->GetPrice() << std::endl;
        }
    }
}

void Inventory::PrintItems(int dummy) {
    std::cout << "ITEMS" << std::endl;
    for (size_t i = 0; i < numElements; i++) {
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
    if (choice > numElements) {
        std::cout << "Please input a valid number" << std::endl;
        this->PrintInven(0);
    } else if (choice != -1) {
        start[choice]->display();
        this->PrintInven(0);
    }
}

void Inventory::GarbageCollection() {
int64_t removedItems = 0;
for (size_t i = 0; i < usedElements; i++) {
    if (start[i]->GetAmount() <= 0) {
        start[i] = nullptr;
        removedItems++;
    }
}
for (size_t j = 0; j < usedElements; j++) {
    if (start[j] == nullptr) {
        for (size_t i = j; i < numElements - 1; i++) {
            start[i] = start[i + 1];
        }
    }
}
usedElements -= removedItems;
}
