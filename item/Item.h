#pragma once

#include <cstdint>
#include <string>
#include "Menu.h"
#include "Entity.h"
#include <vector>
#include <memory>


class Item : public Menu {
  protected:
    std::string name;
    std::string type = "NONE";
    int64_t amount = 1;
    int64_t price = 10;
    bool stackable = true;
    bool equipable = false;
    bool offense = true;
    std::string description;
    void dispatch(int64_t i) override;

  public:
    //Constructor
    Item(std::string itemName, int64_t price, int64_t amnt, std::string desc);
    Item(std::string itemName, int64_t price, std::string desc);
    explicit Item(Item* i);

    // C++ doesn't have virtual constructors, but I don't care
    virtual std::unique_ptr<Item> copy() = 0;

    //Getters
    std::string GetName();
    std::string GetType();
    virtual std::string GetAmntText() = 0;
    std::string GetDesc();
    [[nodiscard]] int64_t GetAmount() const;
    [[nodiscard]] int64_t GetPrice() const;
    [[nodiscard]] bool isStackable() const;
    [[nodiscard]] bool isEquipment() const;
    [[nodiscard]] bool isOffense() const;

    //Setters
    virtual void ChangeAmount(int64_t addAmnt);

    /**
     * @param times Multiplies the current amount by this much
     */
    void copy(int64_t times);

    //Setters I do not think we need
    void SetName(std::string newName);

    void display() override;

    virtual void Use(Entity* user , std::vector< Entity* > opponents);
};