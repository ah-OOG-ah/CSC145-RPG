#include "Item.h"

#include <iostream>
#include <cstdint>
#include <string>
#include <utility>

Item::Item(std::string itemName, int64_t price, std::string desc)
        : Item(std::move(itemName), price, 1, std::move(desc)) { }
Item::Item(std::string itemName, int64_t price, int64_t amnt, std::string desc)
: name(std::move(itemName)), amount(amnt), price(price), description(std::move(desc)), Menu(std::vector<std::string>({itemName,  desc})) { }
Item::Item(Item* i) : Menu(std::vector<std::string>({i->GetName(), i->GetDesc()}))
{
    this->amount = i->GetAmount();
    this->name = i->GetName();
    this->price = i->GetPrice();
    this->description = i->GetDesc();
}

std::string Item::GetName() { return name; }
std::string Item::GetType() { return type; }
std::string Item::GetDesc() { return description; }
int64_t Item::GetAmount() const { return amount; }
int64_t Item::GetPrice() const { return price; }
bool Item::isStackable() const { return stackable; }
bool Item::isEquipment() const { return equipable; }

void Item::ChangeAmount(int64_t addAmnt) {
    amount += addAmnt;
    if (!stackable) amount = amount > 0 ? 1 : 0;
}

void Item::SetName(std::string newName) { name = std::move(newName); }

void Item::copy(int64_t times) { amount *= times; }

void Item::display()
{
    std::cout << entries[0] << std::endl;
    std::cout << "Price: " << this->GetPrice() << std::endl;
    std::cout << entries[1] << std::endl;
    std::cout << "Enter any key to exit " << std::endl;
    std::string choice;
    std::getline(std::cin, choice);
    return;
}

void Item::dispatch(int64_t i)
{
    return;
}

void Item::Use(Entity* user, std::vector<Entity*> opponents) { return; }