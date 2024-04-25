#pragma once

#include <cstdint>
#include <string>
#include <memory>
#include "Item.h"
#include "RegularItems.h"
#include "Equipment.h"


class Inventory {
  protected:
    size_t numElements = 30;
    size_t usedElements = 0;
    std::vector<std::shared_ptr<Item>> start = std::vector<std::shared_ptr<Item>>(numElements, nullptr);

    int64_t gold = 0;

  public:
    //Constructors
    Inventory();
    explicit Inventory(size_t);
    explicit Inventory(const std::vector<std::shared_ptr<Item>>&);
    Inventory(std::initializer_list<const std::shared_ptr<Item>>);

    size_t GetPos(const std::shared_ptr<Item>&);
    std::shared_ptr<Item> GetItem(size_t);
    std::shared_ptr<Item> GetItem(const std::string&);
    [[nodiscard]] int64_t GetGold() const;
    bool AddItem(const std::shared_ptr<Item>&); //Adds to amount if Item already is in Inventory. Bool to see if adding was successful
    bool ReplaceItem(const std::shared_ptr<Item>&); //function called by AddItem when inventory is full. True if item is replaced, else false
    void RemoveItem(int64_t pos, int64_t amnt = 0); //Used instead of ChangeAmount amount is to be removed. 0 in second integer removes all amount of the item
    void RemoveItem(const std::shared_ptr<Item>& thing, int64_t amnt = 0); //Used instead of ChangeAmount amount is to be removed. 0 in second integer removes all amount of the item
    void AddGold(int64_t);

    [[nodiscard]] size_t GetNumElements() const;
    [[nodiscard]] size_t GetUsedElements() const;

    void PrintItems(); //Called by PrintInven
    void PrintItems(int); //Called by functions that need inventory to print with numbers. Integer value is meaningless.
    void PrintInven(); 
    void PrintInven(int dummy = 0);
    void SelectItem(); 

    void GarbageCollection();
};