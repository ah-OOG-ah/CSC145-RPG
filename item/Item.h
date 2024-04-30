#pragma once

#include <cstdint>
#include <string>
#include "Menu.h"
#include "entity/Entity.h"
#include "ItemTypes.h"
#include <vector>
#include <memory>


class Item {
  protected:
    std::string name;
    ItemType type = NONE;
    int64_t amount = 1;
    int64_t price = 10;
    bool stackable = true;
    bool equipable = false;
    bool offense = true;
    int64_t weightPer = 1;
    std::string description;

  public:
    //Constructor
    Item(std::string itemName, int64_t price, int64_t amnt, std::string desc);
    Item(std::string itemName, int64_t price,               std::string desc);

    /**
     * C++ doesn't have virtual constructors, but I don't care. Simulate it.
     *
     * @param amount If nonzero, sets the result's amount to this instead of copying the original's
     */
    [[nodiscard]] virtual std::unique_ptr<Item> copy(int64_t amount) const = 0;

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
    virtual std::unique_ptr<Item> ChangeAmount(int64_t addAmnt);
    virtual std::unique_ptr<Item> setAmount(int64_t amnt);

    /**
     * @param times Multiplies the current amount by this much
     */
    void multiply(int64_t times);

    //Setters I do not think we need
    void SetName(std::string newName);

    /**
     * Items usable in or out of combat should override this. Some items may not be able to implement it, and should
     * inherit from a subclass which blanks it.
     */
    virtual void use(const std::shared_ptr<Entity>& user, const std::vector<std::shared_ptr<Entity>>& allies, const std::vector<std::shared_ptr<Entity>>& opponents) = 0;
};