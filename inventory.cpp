#include "inventory.h"
#include <cstdint>
#include <string>
#include <iostream>


Inventory::Inventory(size_t max) : maxSlots(max) { }
Inventory::Inventory(const Inventory& inv) : maxSlots(inv.maxSlots), curSlots(inv.curSlots), maxWeight(inv.maxWeight), curWeight(inv.curWeight) {
    for (size_t i = 0; i < curSlots; ++i) {
        backing.emplace_back(inv.backing[i]->copy());
    }
}
Inventory::Inventory(const std::vector<std::shared_ptr<Item>>& items) : maxSlots(items.size()), curSlots(maxSlots) {
    for (size_t i = 0; i < maxSlots; ++i) {
        backing.emplace_back(items[i]->copy());
    }
}
Inventory::Inventory(std::initializer_list<const std::shared_ptr<Item>> il) : maxSlots(il.size()), curSlots(maxSlots) {
    for (const auto& i : il) {
        backing.emplace_back(i->copy());
    }
}

size_t Inventory::GetPos(const std::shared_ptr<Item>& checkItem) {
    for (size_t i = 0; i < maxSlots; i++) {
        if (backing[i]->GetName() == checkItem->GetName()) {
            return i;
        }
    }
    return SIZE_MAX;
}

std::shared_ptr<Item> Inventory::GetItem(size_t pos) {
    if (pos >= curSlots) return nullptr;
    return backing[pos];
}

int64_t Inventory::GetGold() const { return gold; }

bool Inventory::AddItem(const std::shared_ptr<Item>& newItem) {
    if (newItem == nullptr) return false;
    if (curWeight + newItem->getWeight() > maxWeight) return false;

    // Checks if we can add it to an existing slot first
    for (size_t i = 0; i < curSlots; i++) {
        if (backing[i]->GetName() == newItem->GetName() && backing[i]->isStackable()) {
            backing[i]->ChangeAmount(newItem->GetAmount());
            curWeight += newItem->getWeight();
            return true;
        }
    }

    // If the inventory is full, we need to swap something
    if (curSlots == maxSlots) {
        return ReplaceItem(newItem);
    }

    // Add it
    ++curSlots;
    backing.push_back(newItem);

    // Track it for fast access later
    switch (newItem->GetType()) {
        case NONE:
        case WEAPON:
        case ARMOR: break;
        case ATTACK: firstAttack = std::min(firstAttack, curSlots); break;
        case HEAL: firstHeal = std::min(firstHeal, curSlots); break;
        case STATUS: firstStatus = std::min(firstStatus, curSlots); break;
    }

    return true;
}

bool Inventory::ReplaceItem(const std::shared_ptr<Item>& newItem) {

    std::cout << "Your INVENTORY is full. Please select item to replace" << std::endl << std::endl;
    std::cout << "Please input the number for the item you want to replace with the "<< newItem->GetName() << std::endl;
    std::cout << "Input a number outside of the range if you do not wish to replace any items" << std::endl;
    PrintItems(1); //Used to print items with numbers by them
    int64_t choice = 0;
    std::cin >> choice; //Choice will substracted by one to account for the fact that array starts as zero but inventory numbers at 1

    if (choice > 0 && choice <= curSlots) {
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
    if (pos >= maxSlots) {
        return;
    }
    backing[pos]->ChangeAmount(-1 * amnt);
    if (backing[pos]->GetAmount() <= 0) {
        backing[pos].reset();
        curSlots--;
        for (size_t i = pos; i < maxSlots - 1; i++) {
            backing[i] = backing[i + 1];
        }
    }
}

void Inventory::RemoveItem(int64_t pos, int64_t amnt) {
    backing[pos]->ChangeAmount(-1 * amnt);
    if (backing[pos]->GetAmount() <= 0) {
        backing[pos].reset();
        curSlots--;
        for (size_t i = pos; i < maxSlots - 1; i++) {
            backing[i] = backing[i + 1];
        }
    }
}

void Inventory::AddGold(int64_t amnt) { gold += amnt; }

size_t Inventory::GetNumElements() const { return maxSlots; }
size_t Inventory::GetUsedElements() const { return curSlots; }

void Inventory::PrintItems() {
    std::cout << "ITEMS" << std::endl;
    for (size_t i = 0; i < maxSlots; i++) {
        if (backing[i] != nullptr) {
            std::cout << backing[i]->GetName() << backing[i]->GetAmntText() << backing[i]->GetAmount() << "  ";
            std::cout << "Price " << backing[i]->GetPrice() << std::endl;
        }
    }
}

void Inventory::PrintItems(int dummy) {
    std::cout << "ITEMS" << std::endl;
    for (size_t i = 0; i < maxSlots; i++) {
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
    if (choice > maxSlots) {
        std::cout << "Please input a valid number" << std::endl;
        this->PrintInven(0);
    } else if (choice != -1) {
        backing[choice]->display();
        this->PrintInven(0);
    }
}

void Inventory::GarbageCollection() {
int64_t removedItems = 0;
for (size_t i = 0; i < curSlots; i++) {
    if (backing[i]->GetAmount() <= 0) {
        backing[i] = nullptr;
        removedItems++;
    }
}
for (size_t j = 0; j < curSlots; j++) {
    if (backing[j] == nullptr) {
        for (size_t i = j; i < maxSlots - 1; i++) {
            backing[i] = backing[i + 1];
        }
    }
}
    curSlots -= removedItems;
}
