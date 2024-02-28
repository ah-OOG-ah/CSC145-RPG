#pragma once

#include <cstdint>
#include <string>

class Item
{
    protected:
    std::string name;
    int64_t amount = 0;

    public:
    //Constructor
    Item(std::string);
    Item(std::string itemName, int64_t amnt);

    //Getters
    std::string GetName();
    virtual std::string GetAmntText() = 0;
    int64_t GetAmount();
    //Setters
    virtual void ChangeAmount(int64_t addAmnt);

    //Setters I do not think we need
    void SetName(std::string newName);
};