#pragma once

#include <cstdint>
#include <string>
#include "Menu.h"
#include "entity/Entity.h"
#include "ItemTypes.h"
#include <vector>
#include <memory>


class Item : public Menu {
  protected:
    std::string name;
    ItemType type = NONE; //Used by functions to understand what type of item the current is
    int64_t amount = 1;
    int64_t price = 10;
    bool stackable = true;
    bool equipable = false;
    bool offense = true;
    int64_t weightPer = 1;
    std::string description;

    void dispatch(int64_t i) override;

  public:
    //Constructor
    Item(std::string itemName, int64_t price, int64_t amnt, std::string desc);
    Item(std::string itemName, int64_t price,               std::string desc);
    explicit Item(const Item* i);

    // C++ doesn't have virtual constructors, but I don't care
    virtual std::unique_ptr<Item> copy() = 0;

    //Getters
    [[nodiscard]] std::string GetName() const;
    [[nodiscard]] ItemType GetType() const;
    [[nodiscard]] virtual std::string GetAmntText() const = 0;
    [[nodiscard]] std::string GetDesc() const;
    [[nodiscard]] int64_t GetAmount() const;
    [[nodiscard]] int64_t getWeight() const;
    [[nodiscard]] int64_t GetPrice() const;
    [[nodiscard]] bool isStackable() const;
    [[nodiscard]] bool isEquipment() const;
    [[nodiscard]] bool isOffense() const;

    /**
     * This is some arbitrary value that can be used to sort items. For example, healing items would want to override
     * this to return the HP healed. Armor might return the total defense, or no override if sorting isn't needed.
     */
    [[nodiscard]] virtual double getValue() const;

    //Setters
    virtual void ChangeAmount(int64_t addAmnt);

    /**
     * @param times Multiplies the current amount by this much
     */
    void copy(int64_t times);

    //Setters I do not think we need
    void SetName(std::string newName);

    void display() override; //Displays item menu

    virtual void use(const std::shared_ptr<Entity>& user, const std::vector<std::shared_ptr<Entity>>& allies, const std::vector<std::shared_ptr<Entity>>& opponents);
};