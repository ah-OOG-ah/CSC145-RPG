#include "Inventory.h"
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

int64_t Inventory::getGold() const { return gold; }
size_t Inventory::getMaxSlots() const { return maxSlots; }
size_t Inventory::getUsedSlots() const { return curSlots; }

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
    print(true); // print items with numbers by them
    size_t choice = 0;
    std::cin >> choice;
    --choice;// account for zero-indexed backing vs 1-indexed presentation

    if (choice < curSlots) {
        std::cout << backing[choice]->GetName() << " was replaced by " << newItem->GetName() << std::endl;

        ItemType one = backing[choice]->GetType();
        ItemType two = newItem->GetType();
        curWeight += newItem->getWeight() - backing[choice]->getWeight();
        backing[choice] = newItem;

        // If the slot's type has been changed, we need to find the first of that type again
        if (one != two) {
            findFirstItems(backing[choice]->GetType());
            findFirstItems(newItem->GetType());
        }

        return true;
    } else {
        std::cout << newItem->GetName() <<" was not added to inventory" << std::endl;
        return false;
    }
}

void Inventory::RemoveItem(size_t pos, int64_t amnt) {
    if (pos >= curSlots) return;

    backing[pos]->ChangeAmount(-1 * amnt);

    if (backing[pos]->GetAmount() <= 0) {
        --curSlots;
        curWeight -= backing[pos]->getWeight();
        backing.erase(std::next(backing.begin(), pos));
    }
}

void Inventory::AddGold(int64_t amnt) { gold += amnt; }

void Inventory::print(bool numbered) {
    std::cout << gold << " gold, " << curWeight << '/' << maxWeight << " kg" << std::endl;
    std::cout << "ITEMS" << std::endl;
    for (size_t i = 0; i < curSlots; i++) {
        if (numbered) std::cout << i + 1 << ". ";
        std::cout << backing[i]->GetName() << backing[i]->GetAmntText() << backing[i]->GetAmount() << "  ";
        std::cout << "Price " << backing[i]->GetPrice() << std::endl;
    }

    if (curSlots < maxSlots) std::cout << maxSlots - curSlots << " empty slots." << std::endl;
}

void Inventory::GarbageCollection() {
    for (size_t i = 0; i < curSlots; i++) {
        if (backing[i]->GetAmount() <= 0) {
            backing.erase(std::next(backing.begin(), i));
            --curSlots;
        }
    }

    // Technically we could try only checking types removed
    // However, this function is meant to catch cases where we missed something anyways, so force a find on everything.
    findFirstItems(HEAL);
    findFirstItems(ATTACK);
    findFirstItems(STATUS);
}

void Inventory::findFirstItems(ItemType type) {
    if (type == NONE || type == ARMOR || type == WEAPON) return;

    auto val = type == HEAL ? &firstHeal : type == STATUS ? &firstStatus : &firstAttack;
    for (size_t i = 0; i < curSlots; ++i) {
        if (backing[i]->GetType() == type) { *val = i; return; }
    }
    *val = SIZE_MAX;
}

size_t Inventory::getFirst(ItemType t) const {
    switch (t) {
        case NONE:
        case WEAPON:
        case ARMOR: return SIZE_MAX;
        case ATTACK: return firstAttack;
        case HEAL: return firstHeal;
        case STATUS: return firstStatus;
    }
}

std::shared_ptr<Item> Inventory::operator[](size_t i) {
    return GetItem(i);
}
