#include "EnemyAI.h"
#include "game.h"
#include <iostream>
#include <utility>


void doOptimalAttack(EAI::UseInfo info, const std::shared_ptr<Enemy>& self, const std::vector<std::shared_ptr<Enemy>>& allies) {
    if (info.isItem) {
        self->inventory[info.index]->use(self, (const std::vector<std::shared_ptr<Entity>> &) allies, { getPlayer() });
    } else {
        EAI::berserker(self, allies);
    }
}

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wunused-parameter"
/**
 * Berserker always attacks.
 */
void EAI::berserker(const std::shared_ptr<Enemy>& user, const std::vector<std::shared_ptr<Enemy>>& allies) {
    auto before = getPHP();
    user->attackEntity(getPlayer());
    std::cout << user->getName() << " attacked for " << before - getPHP() << " damage!" << std::endl;
}
#pragma clang diagnostic pop

/**
 * Idiot has a 50/50 chance of attacking or using a random item. If it tries to use an item but doesn't have one, it
 * just does nothing. What else did you expect? It's an idiot.
 */
void EAI::idiot(const std::shared_ptr<Enemy>& user, const std::vector<std::shared_ptr<Enemy>>& allies) {
    if (randBool()) {
        berserker(user, allies);
    } else {
        // TODO: use items
        std::cout << user->getName() << " did nothing." << std::endl;
    }
}

/**
 * Amateur is a middling quality strategist, but it at least attempts to be smart.
 * It follows the following algorithm:
 * If the inventory is empty, it reverts to berserker.
 * Else, it starts evaluating its items, and will use them (if present) in order:
 *  - Healing if less than half health.
 *  - Status if more than 15 STR weaker than opponent
 * If none succeed, it attacks normally. Amateur can't use attack items.
 */
void EAI::amateur(const std::shared_ptr<Enemy>& user, const std::vector<std::shared_ptr<Enemy>>& allies) {
    if (user->inventory.getUsedSlots() == 0) { berserker(user, allies); }

    auto item = user->inventory.getFirst(HEAL);

    if (item < SIZE_MAX && user->getCurrentHp() < (user->getMaxHp() / 2.0)) {
        user->inventory[item]->use(user, (const std::vector<std::shared_ptr<Entity>> &) allies, { getPlayer() });
        return;
    }

    item = user->inventory.getFirst(STATUS);

    if (item < SIZE_MAX && user->getAttack() < (getPlayer()->getAttack() - 15)) {
        user->inventory[item]->use(user, (const std::vector<std::shared_ptr<Entity>> &) allies, { getPlayer() });
        return;
    }

    berserker(user, allies);
}

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
void EAI::expert(const std::shared_ptr<Enemy>& user, const std::vector<std::shared_ptr<Enemy>>& allies) {
    // Determine the highest attack item, and whether it's better than the weapon
    auto aInfo = EAI::getInfo<AttackItem>(user);

    // Copy the player for use as a test dummy
    auto theirDummy = std::make_unique<EquippedEntity>(*getPlayer());

    // Try to kill
    if (aInfo.isItem) {
        theirDummy->takeDamage(aInfo.value);
    } else {
        theirDummy->takeDamage(user->getAttack());
    }

    // If it worked, do it for real
    if (!theirDummy->getAlive()) {
        doOptimalAttack(aInfo, user, allies);
        return;
    }

    // We can't one-shot, it's time for hard decisions.

    // Are we vulnerable?
    auto pAInfo = EAI::getInfo<AttackItem>(getPlayer());
    auto ourDummy = std::make_unique<Enemy>(*user);

    if (aInfo.isItem) {
        ourDummy->takeDamage(pAInfo.value);
    } else {
        ourDummy->takeDamage(getPlayer()->getAttack());
    }

    // If it worked, there's nothing to lose - go out in a blaze of glory!
    if (!ourDummy->getAlive()) {
        doOptimalAttack(aInfo, user, allies);
        return;
    }

    // We live another round - check heals and status items

    // Use a heal if it's worth it
    auto hInfo = EAI::getInfo<HealItem>(user);
    if (user->getMaxHp() - user->getCurrentHp() >= hInfo.value) {
        user->inventory[hInfo.index]->use(user, (const std::vector<std::shared_ptr<Entity>>&) allies, { getPlayer() });
        return;
    }

    // Compare status vs attack
    auto sInfo = EAI::getInfo<StatusItem>(user);
    if (sInfo.value > aInfo.value / 2) {
        user->inventory[sInfo.index]->use(user, (const std::vector<std::shared_ptr<Entity>>&) allies, { getPlayer() });
        return;
    } else {

        // Just punch it already
        doOptimalAttack(aInfo, user, allies);
        return;
    }
}

/**
 * Prioritizes healing above everything else. Not particularly useful if it's the only enemy...
 * It follows the following algorithm:
 * If it has a healing item, it uses the healing item. Otherwise, does nothing.
 * What did you think it'd do?
 */
void EAI::healer(const std::shared_ptr<Enemy>& user, const std::vector<std::shared_ptr<Enemy>>& allies) {
    auto item = user->inventory.getFirst(HEAL);

    if (item < SIZE_MAX) {
        user->inventory[item]->use(user, (const std::vector<std::shared_ptr<Entity>> &) allies, { getPlayer() });
        return;
    }

    std::cout << user->getName() << " did nothing." << std::endl;
}

void EAI::itemHappy(std::shared_ptr<Enemy> user, std::vector<std::shared_ptr<Enemy>> allies) {
    double weaponDmg = 1.0;
    if (user->currentWeapon != nullptr) {
        weaponDmg = user->currentWeapon->GetDamage();
    }
    int64_t invenSize = user->inventory.getUsedSlots();
    if (invenSize > 0) {
        user->inventory.GetItem(randUint() % invenSize);
    } else {
        target->changeHP(-1 * user->getAttack() * weaponDmg);
    }
}

std::function<void(std::shared_ptr<Enemy>, std::vector<std::shared_ptr<Enemy>>)> EAI::get(EnumAI which) {
    switch (which) {
        case IDIOT:      return [](auto e, auto a) { idiot(std::move(e), std::move(a)); };
        case BERSERKER:  return [](auto e, auto a) { berserker(std::move(e), std::move(a)); };
        case AMATEUR:    return [](auto e, auto a) { amateur(std::move(e), std::move(a)); };
        case EXPERT:     return [](auto e, auto a) { expert(std::move(e), std::move(a)); };
        case HEALER:     return [](auto e, auto a) { healer(std::move(e), std::move(a)); };
        case ITEM_HAPPY: return [](auto e, auto a) { itemHappy(std::move(e), std::move(a)); };
    }
}
