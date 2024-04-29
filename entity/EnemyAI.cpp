#include "EnemyAI.h"
#include "game.h"
#include <iostream>
#include <utility>


template<class T> EAI::UseInfo EAI::getInfo(const std::shared_ptr<EquippedEntity>& e) {
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

template<> EAI::UseInfo EAI::getInfo<AttackItem>(const std::shared_ptr<EquippedEntity>& e) {
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

void doOptimalAttack(EAI::UseInfo info, const std::shared_ptr<Enemy>& self, const std::vector<std::shared_ptr<Enemy>>& allies) {
    if (info.isItem) {
        self->inventory[info.index]->use(self, (const std::vector<std::shared_ptr<Entity>> &) allies, { getPlayer() });
    } else {
        EAI::berserker(self, allies);
    }
}

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wunused-parameter"
void EAI::berserker(const std::shared_ptr<Enemy>& user, const std::vector<std::shared_ptr<Enemy>>& allies) {
    auto before = getPHP();
    user->attackEntity(getPlayer());
    std::cout << user->getName() << " attacked for " << before - getPHP() << " damage!" << std::endl;
}
#pragma clang diagnostic pop

void EAI::idiot(const std::shared_ptr<Enemy>& user, const std::vector<std::shared_ptr<Enemy>>& allies) {
    if (randBool()) {
        berserker(user, allies);
    } else {
        // TODO: use items
        std::cout << user->getName() << " did nothing." << std::endl;
    }
}

void EAI::amateur(const std::shared_ptr<Enemy>& user, const std::vector<std::shared_ptr<Enemy>>& allies) {
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

void EAI::healer(const std::shared_ptr<Enemy>& user, const std::vector<std::shared_ptr<Enemy>>& allies) {
    auto item = user->inventory.getFirst(HEAL);

    if (item < SIZE_MAX) {
        user->inventory[item]->use(user, (const std::vector<std::shared_ptr<Entity>> &) allies, { getPlayer() });
        return;
    }

    std::cout << user->getName() << " did nothing." << std::endl;
}

void EAI::itemHappy(const std::shared_ptr<Enemy>& user, const std::vector<std::shared_ptr<Enemy>>& allies) {

    if (user->inventory.getUsedSlots() > 0) {
        user->inventory[0]->use(user, (const std::vector<std::shared_ptr<Entity>> &) allies, { getPlayer() });
        return;
    }

    berserker(user, allies);
}

std::function<void(const std::shared_ptr<Enemy>&, const std::vector<std::shared_ptr<Enemy>>&)> EAI::get(EnumAI which) {
    switch (which) {
            case IDIOT:      return [](auto e, auto a) { idiot(std::move(e), std::move(a)); };
        case BERSERKER:  return [](auto e, auto a) { berserker(std::move(e), std::move(a)); };
        case AMATEUR:    return [](auto e, auto a) { amateur(std::move(e), std::move(a)); };
        case EXPERT:     return [](auto e, auto a) { expert(std::move(e), std::move(a)); };
        case HEALER:     return [](auto e, auto a) { healer(std::move(e), std::move(a)); };
        case ITEM_HAPPY: return [](auto e, auto a) { itemHappy(std::move(e), std::move(a)); };
    }
}
