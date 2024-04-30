#include "Item.h"

#include <iostream>
#include <cstdint>
#include <string>
#include <utility>


Item::Item(std::string itemName, int64_t price, std::string desc)
    : Item(std::move(itemName), price, 1, std::move(desc)) { }
Item::Item(std::string itemName, int64_t price, int64_t amnt, std::string desc)
    : name(std::move(itemName)), amount(amnt), price(price), description(std::move(desc)) { }


std::string Item::GetName() const { return name; }
ItemType Item::GetType() const { return type; }
std::string Item::GetDesc() const { return description; }
int64_t Item::GetAmount() const { return amount; }
int64_t Item::getWeight() const { return weightPer * amount; }
int64_t Item::GetPrice() const { return price; }
bool Item::isStackable() const { return stackable; }
bool Item::isEquipment() const { return equipable; }
bool Item::isOffense() const { return offense; }

void Item::ChangeAmount(int64_t addAmnt) {
    amount += addAmnt;
    if (!stackable) amount = amount > 0 ? 1 : 0;
}

void Item::SetName(std::string newName) { name = std::move(newName); }

void Item::multiply(int64_t times) { amount *= times; }

double Item::getValue() const {
    return 0;
}

std::unique_ptr<Item> Item::setAmount(int64_t amnt) {
    auto delta = amnt;

    amount = amnt;
    if (!stackable) amount = amount > 0 ? 1 : 0;

    // Return any excess
    delta -= amount;
    if (delta > 0) return copy(delta);
    return nullptr;
}
