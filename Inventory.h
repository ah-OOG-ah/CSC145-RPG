#pragma once

#include <cstdint>
#include <string>
#include <memory>
#include "Item.h"
#include "RegularItems.h"
#include "Equipment.h"


class Inventory {
  private:
    /**
     * Scans the inventory for the first item of the given type. If it is NONE, ARMOR, or WEAPON, it does not scan.
     */
    void findFirstItems(ItemType type);

  protected:
    size_t maxSlots = 30;
    size_t curSlots = 0;
    int64_t maxWeight = 50;
    int64_t curWeight = 0;
    std::vector<std::shared_ptr<Item>> backing;

    int64_t gold = 0;

    size_t firstHeal = SIZE_MAX;
    size_t firstStatus = SIZE_MAX;
    size_t firstAttack = SIZE_MAX;

  public:
    explicit Inventory(size_t max = 30);

    // These copy constructors are deep copies - they copy the underlying items as well as the container.
    Inventory(const Inventory&);
    explicit Inventory(const std::vector<std::shared_ptr<Item>>&);
    Inventory(std::initializer_list<const std::shared_ptr<Item>>);

    [[nodiscard]] int64_t getGold() const;
    [[nodiscard]] size_t getMaxSlots() const;
    [[nodiscard]] size_t getUsedSlots() const;

    [[nodiscard]] size_t getFirst(ItemType) const;

    size_t GetPos(const std::shared_ptr<Item>&);
    std::shared_ptr<Item> operator[] (size_t);
    bool ReplaceItem(const std::shared_ptr<Item>&); // function called by AddItem when inventory is full. True if item is replaced, else false
    std::unique_ptr<Item> RemoveItem(size_t pos, int64_t amnt = 0); // Used instead of ChangeAmount amount is to be removed. 0 in second integer removes all amount of the item
    void AddGold(int64_t);
    void changeWeight(int64_t);

    /**
     * Attempts to add the item to the inventory. Does not copy it, be careful!
     *
     * @return True if the item was added.
     */
    bool AddItem(const std::shared_ptr<Item>&);

    /**
     * Prints the inventory.
     */
    void print(bool numbered);

    void GarbageCollection();
};