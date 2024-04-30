#include "Item.h"

#include <iostream>
#include <cstdint>
#include <string>
#include <utility>


Item::Item(std::string itemName, int64_t price, std::string desc)
        : Item(std::move(itemName), price, 1, std::move(desc)) { }
Item::Item(std::string itemName, int64_t price, int64_t amnt, std::string desc)
: Menu(std::vector<std::string>({itemName,  desc})), name(std::move(itemName)), amount(amnt), price(price), description(std::move(desc)) { }
Item::Item(const Item* i)
    : Menu(std::vector<std::string>({i->GetName(), i->GetDesc()})),
    name(i->name), type(i->type), amount(i->amount), price(i->price), stackable(i->stackable), equipable(i->equipable), offense(i->offense), description(i->description) { }

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

void Item::copy(int64_t times) { amount *= times; }

void Item::display() {
    std::cout << entries[0] << std::endl;
    std::cout << "Price: " << this->GetPrice() << std::endl;
    std::cout << entries[1] << std::endl;
    std::cout << "Enter any key to exit " << std::endl;
    std::string choice;
    std::getline(std::cin, choice);
}

void Item::dispatch(int64_t i) { }

void Item::use(const std::shared_ptr<Entity>& user, const std::vector<std::shared_ptr<Entity>>& allies, const std::vector<std::shared_ptr<Entity>>& opponents) { }

double Item::getValue() const {
    return 0;
}

void Item::setAmount(int64_t amnt) {
    amount = amnt;
    if (!stackable) amount = amount > 0 ? 1 : 0;
}
