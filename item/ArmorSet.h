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

    std::shared_ptr<Armor> operator[] (std::size_t idx) const { return get(idx); }

    void set(std::shared_ptr<Armor> a) {
        switch (a->GetArmorType()) {
            case Helmet: head = a;
                break;
            case Chestplate: chest = a;
                break;
            case Leggings: legs = a;
                break;
            case Boots: feet = a;
        }
    }
};