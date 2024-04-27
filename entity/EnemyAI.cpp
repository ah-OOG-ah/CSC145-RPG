#include "EnemyAI.h"
#include "game.h"
#include <iostream>
#include <utility>


void EAI::idiot(std::shared_ptr<Enemy> user, std::vector<std::shared_ptr<Enemy>> allies) {
    if (randBool()) {
        user->attackEntity(target);
    } else {
        //user->inventory.GetItem(randUint() % user->inventory.GetUsedElements());
    }
}

void EAI::berserker(std::shared_ptr<Enemy> user, std::vector<std::shared_ptr<Enemy>> allies) {
    double weaponDmg = 1.0;
    if (user->currentWeapon != nullptr) {
        weaponDmg = user->currentWeapon->GetDamage();
    }
    target->changeHP(-1 * user->getAttack() * weaponDmg);
}

void EAI::amateur(std::shared_ptr<Enemy> user, std::vector<std::shared_ptr<Enemy>> allies) {
    double weaponDmg = 1.0;
    if (user->currentWeapon != nullptr) {
        weaponDmg = user->currentWeapon->GetDamage();
    }
    if (user->getCurrentHp() < (user->getMaxHp() / 2.0)) {
        int64_t healOrDef = randUint() % 3;
        if (healOrDef < 2) {
            for (int i = 0; i < user->inventory.GetUsedElements(); i++) {
                if (user->inventory.GetItem(i)->GetType() == "HEAL") {
                    user->inventory.GetItem(i)->Use(user, { target });
                    return;
                }
            }
            target->changeHP(-1 * user->getAttack() * weaponDmg);
        } else {
            for (int i = 0; i < user->inventory.GetUsedElements(); i++) {
                if (user->inventory.GetItem(i)->GetType() == "STATUS") {
                    user->inventory.GetItem(i)->Use(user, { target });
                    return;
                }
            }
            target->changeHP(-1 * user->getAttack() * weaponDmg);
        }
    } else if (user->getAttack() < (target->getAttack() - 15)) {
        for (int i = 0; i < user->inventory.GetUsedElements(); i++) {
            if (user->inventory.GetItem(i)->GetType() == "STATUS") {
                user->inventory.GetItem(i)->Use(user, { target });
                return;
            }
        }
        target->changeHP(-1 * user->getAttack() * weaponDmg);
    } else {
        if (randBool()) {
            target->changeHP(-1 * user->getAttack() * weaponDmg);
        } else {
            user->inventory.GetItem(randUint() % user->inventory.GetUsedElements());
        }
    }
}

void EAI::expert(std::shared_ptr<Enemy> user, std::vector<std::shared_ptr<Enemy>> allies) {
    double weaponDmg = 1.0;
    if (user->currentWeapon != nullptr) {
        weaponDmg = user->currentWeapon->GetDamage();
    }
    if (user->getCurrentHp() < (user->getMaxHp() / 2.0)) {
        for (int i = 0; i < user->inventory.GetUsedElements(); i++) {
            if (user->inventory.GetItem(i)->GetType() == "HEAL") {
                user->inventory.GetItem(i)->Use(user, { target });
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
            for (int i = 0; i < user->inventory.GetUsedElements(); i++) {
                if (user->inventory.GetItem(i)->GetType() == "ARMOR") {
                    user->inventory.GetItem(i)->Use(user, { target });
                    return;
                } 
            }
        }
        int64_t attkOrItem = randUint() % 5;
        if (attkOrItem > 0) {
            target->changeHP(-1 * user->getAttack() * weaponDmg);
        } else {
            user->inventory.GetItem(randUint() % user->inventory.GetUsedElements());
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
        for (int i = 0; i < user->inventory.GetUsedElements(); i++) {
            if (user->inventory.GetItem(i)->GetType() == "HEAL") {
                user->inventory.GetItem(i)->Use(user, { target });
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
    int64_t invenSize = user->inventory.GetUsedElements();
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
