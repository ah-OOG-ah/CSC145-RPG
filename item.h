#pragma once

#include <cstdint>
#include <string>
#include "Menu.h"

class Item : public Menu{
  protected:
    std::string name;
    int64_t amount = 1;
    int64_t price = 10;
    bool stackable = true;
    bool equipable = false;
    std::string description;
    void dispatch(int64_t i) override;
  public:
    //Constructor
    Item(std::string itemName, int64_t price, int64_t amnt, std::string desc);
    Item(std::string itemName, int64_t price, std::string desc);

    //Getters
    std::string GetName();
    virtual std::string GetAmntText() = 0;
    std::string GetDesc();
    [[nodiscard]] int64_t GetAmount() const;
    [[nodiscard]] int64_t GetPrice() const;
    [[nodiscard]] bool isStackable() const;
    [[nodiscard]] bool isEquipment() const;

    void display() override;

    //Setters
    virtual void ChangeAmount(int64_t addAmnt);

    //Setters I do not think we need
    void SetName(std::string newName);
};