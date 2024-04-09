#pragma once

#include <cstdint>
#include <string>

class Item
{
    protected:
    std::string name;
    int64_t amount = 0;
    int64_t price = 0;

    public:
    //Constructor
    Item() { }
    Item(std::string itemName,int64_t price, int64_t amnt);
    Item(std::string itemName, int64_t price);

    //Getters
    std::string GetName();
    virtual std::string GetAmntText() = 0;
    int64_t GetAmount() const;
    int64_t GetPrice() const;
    //Setters
    virtual void ChangeAmount(int64_t addAmnt);

    //Setters I do not think we need
    void SetName(std::string newName);
};