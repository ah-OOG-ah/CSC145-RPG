#pragma once

#include "Equipment.h"
#include <memory>


struct ArmorSet {
    std::shared_ptr<Armor> head{};
    std::shared_ptr<Armor> chest{};
    std::shared_ptr<Armor> legs{};
    std::shared_ptr<Armor> feet{};

    [[nodiscard]] std::shared_ptr<Armor> get(size_t i) const {
        switch (i) {
            case 0: return head;
            case 1: return chest;
            case 2: return legs;
            default: return feet;
        }
    }
};