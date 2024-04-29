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
     * Determine the highest value item in an entity's inventory.
     */
    template<class T> UseInfo getInfo(const std::shared_ptr<EquippedEntity>& e);

    /**
     * A specialization that also compares with the user's weapon.
     */
    template<> UseInfo getInfo<AttackItem>(const std::shared_ptr<EquippedEntity>& e);

    /**
     * Berserker always attacks.
     */
    static void berserker(const std::shared_ptr<Enemy>& user, const std::vector<std::shared_ptr<Enemy>>& allies);

    /**
     * Idiot has a 50/50 chance of attacking or using a random item. If it tries to use an item but doesn't have one, it
     * just does nothing. What else did you expect? It's an idiot.
     *
     * Still technically more complex than berserker tho.
     */
    static void idiot(const std::shared_ptr<Enemy>& user, const std::vector<std::shared_ptr<Enemy>>& allies);

    /**
     * Amateur is a middling quality strategist, but it at least attempts to be smart.
     * It follows the following algorithm:
     * If the inventory is empty, it reverts to berserker.
     * Else, it starts evaluating its items, and will use them (if present) in order:
     *  - Healing if less than half health.
     *  - Status if more than 15 STR weaker than opponent
     * If none succeed, it attacks normally. Amateur can't use attack items.
     */
    static void amateur(const std::shared_ptr<Enemy>& user, const std::vector<std::shared_ptr<Enemy>>& allies);

    /**
     * Expert attempts to play optimally.
     * It follows the following algorithm:
     * First, determine it's highest-power attack, heal, and status items.
     * If it can kill, attack (may be with item).
     * If not, it checks if it can be killed
     *  - if it can heal or status out of this, do so (prefer status)
     *  - if not, do the most damage possible
     * If it won't be killed, choose the highest "getValue" action - heal if the heal can be fully exploited, status if that
     * boosts it by more than half its best damage, optimal attack otherwise.
     *
     * Expert isn't a *perfect* strategist - it doesn't account for group effects or damage over time, and can't predict
     * more than one move in the future. But it's more capable than amateur.
     *
     * TODO: account for simple poison/regen case, and maybe paralysis too
     */
    static void expert(const std::shared_ptr<Enemy>& user, const std::vector<std::shared_ptr<Enemy>>& allies);

    /**
     * Prioritizes healing above everything else. Not particularly useful if it's the only enemy...
     * It follows the following algorithm:
     * If it has a healing item, it uses the healing item. Otherwise, does nothing.
     * What did you think it'd do?
     */
    static void healer(const std::shared_ptr<Enemy>& user, const std::vector<std::shared_ptr<Enemy>>& allies);

    /**
     * Uses items if at all possible.
     * It follows the following algorithm:
     * If it has an item, it uses it. Otherwise, attacks.
     * Unlike idiot and healer, this one is actually useful without items. I know, shocking.
     */
    static void itemHappy(const std::shared_ptr<Enemy>& user, const std::vector<std::shared_ptr<Enemy>>& allies);

    std::function<void(const std::shared_ptr<Enemy>&,const std::vector<std::shared_ptr<Enemy>>&)> get(EnumAI);
}