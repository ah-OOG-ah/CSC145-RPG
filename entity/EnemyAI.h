#pragma once

#include "Enemy.h"
#include "Entity.h"


namespace EAI {

    /**
     * Used to store state internally for the expert AI
     */
    struct AttackInfo {
        double attack = 0;
        size_t index = SIZE_MAX;
        bool isItem = false;
    };

    static AttackInfo getAttackInfo(const std::shared_ptr<EquippedEntity>&);

    static void idiot(const std::shared_ptr<Enemy>& user, const std::vector<std::shared_ptr<Enemy>>& allies);
    static void berserker(const std::shared_ptr<Enemy>& user, const std::vector<std::shared_ptr<Enemy>>& allies);
    static void amateur(const std::shared_ptr<Enemy>& user, const std::vector<std::shared_ptr<Enemy>>& allies);
    static void expert(const std::shared_ptr<Enemy>& user, const std::vector<std::shared_ptr<Enemy>>& allies);
    static void healer(std::shared_ptr<Enemy> user, std::vector<std::shared_ptr<Enemy>> allies);
    static void itemHappy(std::shared_ptr<Enemy> user, std::vector<std::shared_ptr<Enemy>> allies);

    std::function<void(std::shared_ptr<Enemy>,std::vector<std::shared_ptr<Enemy>>)> get(EnumAI);
}