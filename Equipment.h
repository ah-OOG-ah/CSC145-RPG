#pragma once

#include <string>
#include <cstdint>
#include "item.h"
#include "Status.h"

class Equipment : public Item
{
    protected:
    std::string durability = "durability";

    public:
    Equipment(std::string itemName, int64_t amnt);
    std::string GetAmntText() override;
};