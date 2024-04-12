#include "item.h"

#include <cstdint>
#include <string>
#include <utility>

Item::Item() { }
Item::Item(std::string itemName, int64_t price, int64_t amnt, std::string desc) : name(std::move(itemName)), amount(amnt), price(price), description(std::move(desc)) { }
Item::Item(std::string itemName, int64_t price, std::string desc) : name(std::move(itemName)), price(price), description(std::move(desc)){ }

std::string Item::GetName() { return name; }
std::string Item::GetDesc() { return description; }
int64_t Item::GetAmount() const { return amount; }
int64_t Item::GetPrice() const { return price; }
bool Item::isStackable() { return stackable; }
bool Item::isEquipment() { return equipable; }


void Item::ChangeAmount(int64_t addAmnt) { amount += addAmnt; }

void Item::SetName(std::string newName) { name = std::move(newName); }
