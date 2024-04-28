#pragma once

#include "Equipment.h"
#include <memory>


struct ArmorSet {

    std::shared_ptr<Armor> head;
    std::shared_ptr<Armor> chest;
    std::shared_ptr<Armor> legs;
    std::shared_ptr<Armor> feet;

    ArmorSet(const std::shared_ptr<Armor>& h, const std::shared_ptr<Armor>& c, const std::shared_ptr<Armor>& l, const std::shared_ptr<Armor>& f) {
        head.reset(dynamic_cast<Armor*>(h->copy().release()));
        chest.reset(dynamic_cast<Armor*>(c->copy().release()));
        legs.reset(dynamic_cast<Armor*>(l->copy().release()));
        feet.reset(dynamic_cast<Armor*>(f->copy().release()));
    }

    ArmorSet(const ArmorSet& a) {
        head.reset(dynamic_cast<Armor*>(a.head->copy().release()));
        chest.reset(dynamic_cast<Armor*>(a.chest->copy().release()));
        legs.reset(dynamic_cast<Armor*>(a.legs->copy().release()));
        feet.reset(dynamic_cast<Armor*>(a.feet->copy().release()));
    }

    ArmorSet() = default;

    [[nodiscard]] double offenseMult() const {
        return (head->GetDmgMult() + chest->GetDmgMult() + legs->GetDmgMult() + feet->GetDmgMult()) / 4.0;
    }
    [[nodiscard]] double defenseMult() const {
        return (head->GetPercDef() + chest->GetPercDef() + legs->GetPercDef() + feet->GetPercDef()) / 4.0;
    }
    [[nodiscard]] double defenseStatic() const {
        return (head->GetStaticDef() + chest->GetStaticDef() + legs->GetStaticDef() + feet->GetStaticDef()) / 4.0;
    }

    [[nodiscard]] std::shared_ptr<Armor> get(size_t i) const {
        switch (i) {
            case 0: return head;
            case 1: return chest;
            case 2: return legs;
            default: return feet;
        }
    }

    std::shared_ptr<Armor> operator[] (std::size_t idx) const { return get(idx); }

    void set(const std::shared_ptr<Armor>& a) {
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