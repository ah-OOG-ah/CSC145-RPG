#include "item.h"

#include <cstdint>
#include <string>
#include <utility>

Item::Item(std::string itemName) : name(std::move(itemName)) { }
Item::Item(std::string itemName, int64_t amnt) : name(std::move(itemName)), amount(amnt) { }
Item::Item(std::string itemName, int64_t amnt, int64_t price) : name(std::move(itemName)), amount(amnt), price(price) { }

std::string Item::GetName() { return name; }
int64_t Item::GetAmount() const { return amount; }
int64_t Item::GetPrice() const { return price; }


void Item::ChangeAmount(int64_t addAmnt) { amount += addAmnt; }

void Item::SetName(std::string newName) { name = std::move(newName); }
