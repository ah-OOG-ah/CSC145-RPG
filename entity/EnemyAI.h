#pragma once

#include "Enemy.h"
#include "Entity.h"


namespace EAI {

    /**
     * Used to store state internally for the expert AI
     */
    struct UseInfo {
        double value = 0;
        size_t index = SIZE_MAX;
        bool isItem = false;
    };

    /**
     * Determine the highest value item.
     */
    template<class T> UseInfo getInfo(const std::shared_ptr<EquippedEntity>& e) {
        double value = 0;
        size_t index = SIZE_MAX;
        for (size_t i = 0; i < e->inventory.getUsedSlots(); ++i) {
            auto a = dynamic_cast<T*>(e->inventory[i].get());
            if (a == nullptr) continue;

            if (value < a->getValue()) {
                value = a->getValue();
                index = i;
            }
        }

        return { value, index, true };
    }

    /**
     * A specialization that also compares with the user's weapon.
     */
    template<> UseInfo getInfo<AttackItem>(const std::shared_ptr<EquippedEntity>& e) {
        double value = 0;
        size_t index = SIZE_MAX;
        for (size_t i = 0; i < e->inventory.getUsedSlots(); ++i) {
            if (e->inventory[i]->GetType() == ATTACK) {
                auto a = dynamic_cast<AttackItem*>(e->inventory[i].get());

                if (value < a->GetDamage()) {
                    value = a->GetDamage();
                    index = i;
                }
            }
        }
        bool isItem = e->getAttack() < value;

        return { value, index, isItem };
    }

    static void idiot(const std::shared_ptr<Enemy>& user, const std::vector<std::shared_ptr<Enemy>>& allies);
    static void berserker(const std::shared_ptr<Enemy>& user, const std::vector<std::shared_ptr<Enemy>>& allies);
    static void amateur(const std::shared_ptr<Enemy>& user, const std::vector<std::shared_ptr<Enemy>>& allies);
    static void expert(const std::shared_ptr<Enemy>& user, const std::vector<std::shared_ptr<Enemy>>& allies);
    static void healer(const std::shared_ptr<Enemy>& user, const std::vector<std::shared_ptr<Enemy>>& allies);
    static void itemHappy(std::shared_ptr<Enemy> user, std::vector<std::shared_ptr<Enemy>> allies);

    std::function<void(std::shared_ptr<Enemy>,std::vector<std::shared_ptr<Enemy>>)> get(EnumAI);
}