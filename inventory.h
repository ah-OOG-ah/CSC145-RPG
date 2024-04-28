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

    size_t GetPos(const std::shared_ptr<Item>&);
    std::shared_ptr<Item> GetItem(size_t);
    [[nodiscard]] int64_t GetGold() const;
    bool ReplaceItem(const std::shared_ptr<Item>&); //function called by AddItem when inventory is full. True if item is replaced, else false
    void RemoveItem(int64_t pos, int64_t amnt = 0); //Used instead of ChangeAmount amount is to be removed. 0 in second integer removes all amount of the item
    void RemoveItem(const std::shared_ptr<Item>& thing, int64_t amnt = 0); //Used instead of ChangeAmount amount is to be removed. 0 in second integer removes all amount of the item
    void AddGold(int64_t);

    /**
     * Attempts to add the item to the inventory. Does not copy it, be careful!
     * TODO: check weight limits
     *
     * @return True if the item was added.
     */
    bool AddItem(const std::shared_ptr<Item>&);

    [[nodiscard]] size_t GetNumElements() const;
    [[nodiscard]] size_t GetUsedElements() const;

    void PrintItems(); //Called by PrintInven
    void PrintItems(int); //Called by functions that need inventory to print with numbers. Integer value is meaningless.
    void PrintInven(); 
    void PrintInven(int dummy = 0);
    void SelectItem(); 

    void GarbageCollection();
};