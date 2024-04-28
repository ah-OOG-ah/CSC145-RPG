#include "EnemyAI.h"
#include "game.h"
#include <iostream>
#include <utility>


/**
 * Berserker always attacks.
 */
void EAI::berserker(const std::shared_ptr<Enemy>& user, const std::vector<std::shared_ptr<Enemy>>& allies) {
    auto before = getPHP();
    user->attackEntity(getPlayer());
    std::cout << user->getName() << " attacked for " << before - getPHP() << " damage!" << std::endl;
}

/**
 * Idiot has a 50/50 chance of attacking or using a random item. If it tries to use an item but doesn't have one, it
 * just does nothing. What else did you expect? It's an idiot.
 */
void EAI::idiot(const std::shared_ptr<Enemy>& user, const std::vector<std::shared_ptr<Enemy>>& allies) {
    if (randBool()) {
        berserker(user, allies);
    } else {
        //user->inventory.GetItem(randUint() % user->inventory.GetUsedElements());
        std::cout << user->getName() << " did nothing." << std::endl;
    }
}

/**
 * Amateur is a middling quality strategist, but it at least attempts to be smart.
 * It follows the following algorithm:
 * If the inventory is empty, it reverts to berserker.
 * Else, it starts evaluating its items, and will use them (if present) in order:
 *  - Healing if less than half health.
 *  - Status if weaker than opponent
 * If none succeed, it attacks normally. Amateur can't use attack items.
 */
void EAI::amateur(const std::shared_ptr<Enemy>& user, const std::vector<std::shared_ptr<Enemy>>& allies) {

    if (user->inventory.getUsedSlots() == 0) {
        berserker(user, allies);
    }

    double weaponDmg = 1.0;
    if (user->currentWeapon != nullptr) {
        weaponDmg = user->currentWeapon->GetDamage();
    }

    auto item = user->inventory.getFirst(HEAL);

    if (item < SIZE_MAX && user->getCurrentHp() < (user->getMaxHp() / 2.0)) {

        std::cout << user->getName() << " used " << user->inventory[item]->GetName() << std::endl;
        user->inventory[item]->use(user, (const std::vector<std::shared_ptr<Entity>> &) allies, { getPlayer() });
    } else if (user->getAttack() < (target->getAttack() - 15)) {
        for (int i = 0; i < user->inventory.getUsedSlots(); i++) {
            if (user->inventory.GetItem(i)->GetType() == "STATUS") {
                user->inventory.GetItem(i)->use(user, {target}, <#initializer#>);
                return;
            }
        }
        target->changeHP(-1 * user->getAttack() * weaponDmg);
    } else {
        if (randBool()) {
            target->changeHP(-1 * user->getAttack() * weaponDmg);
        } else {
            user->inventory.GetItem(randUint() % user->inventory.getUsedSlots());
        }
    }
}

void EAI::expert(std::shared_ptr<Enemy> user, std::vector<std::shared_ptr<Enemy>> allies) {
    double weaponDmg = 1.0;
    if (user->currentWeapon != nullptr) {
        weaponDmg = user->currentWeapon->GetDamage();
    }
    if (user->getCurrentHp() < (user->getMaxHp() / 2.0)) {
        for (int i = 0; i < user->inventory.getUsedSlots(); i++) {
            if (user->inventory.GetItem(i)->GetType() == "HEAL") {
                user->inventory.GetItem(i)->use(user, {target}, <#initializer#>);
                return;
            }
        }
        target->changeHP(-1 * user->getAttack() * weaponDmg);
    } /*else if (user->currentWeapon->GetDamage() < (target->currentWeapon->GetDamage())) {
        for (int i = 0; i < user->Inven.GetUsedElements(); i++) {
            if (user->Inven.GetItem(i)->GetType() == "WEAPON") {
                user->Inven.GetItem(i)->Use(user, std::vector<Entity*>{target});
                return;
            } 
        }
        for (int i = 0; i < user->Inven.GetUsedElements(); i++) {
            if(user->Inven.GetItem(i)->GetType() == "Status") {
                user->Inven.GetItem(i)->Use(user, std::vector<Entity*>{target});
                return;
            } 
        }
        target->changeHP(-1 * user->getAttk() * weaponDmg);
}*/ else {
        uint64_t armorChoice = randUint() % 4;
        if (user->armor[armorChoice]->GetPercDef() < user->armor[armorChoice]->GetPercDef()
         || user->armor[armorChoice]->GetStaticDef() < user->armor[armorChoice]->GetStaticDef()
         || user->armor[armorChoice]->GetDurab() < 14) {
            for (int i = 0; i < user->inventory.getUsedSlots(); i++) {
                if (user->inventory.GetItem(i)->GetType() == "ARMOR") {
                    user->inventory.GetItem(i)->use(user, {target}, <#initializer#>);
                    return;
                } 
            }
        }
        int64_t attkOrItem = randUint() % 5;
        if (attkOrItem > 0) {
            target->changeHP(-1 * user->getAttack() * weaponDmg);
        } else {
            user->inventory.GetItem(randUint() % user->inventory.getUsedSlots());
        }
    }
}

void EAI::healer(std::shared_ptr<Enemy> user, std::vector<std::shared_ptr<Enemy>> allies) {
    double weaponDmg = 1.0;
    if (user->currentWeapon != nullptr) {
        weaponDmg = user->currentWeapon->GetDamage();
    }
    int64_t healChance = randUint() % 3;
    if (healChance < 2) {
        for (int i = 0; i < user->inventory.getUsedSlots(); i++) {
            if (user->inventory.GetItem(i)->GetType() == "HEAL") {
                user->inventory.GetItem(i)->use(user, {target}, <#initializer#>);
                return;
            }
        }
        target->changeHP(-1 * user->getAttack() * weaponDmg);
    } else {
        target->changeHP(-1 * user->getAttack() * weaponDmg);
    }
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
