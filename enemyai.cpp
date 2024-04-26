#include "enemyai.h"
#include "game.h"
#include <iostream>


void EAI::DefaultAI(Enemy* user, Entity* target) {
    if (randBool()) {
        double weaponDmg = 1.0;
        if (user->currentWeapon != nullptr) {
            weaponDmg = user->currentWeapon->GetDamage();
        }
        target->changeHP(-1 * user->getAttack() * weaponDmg);
    } else {
        user->Inven.GetItem(randUint() % user->Inven.GetUsedElements());
    }
}

void EAI::AttackOnly(Enemy* user, Entity* target) {
    double weaponDmg = 1.0;
    if (user->currentWeapon != nullptr) {
        weaponDmg = user->currentWeapon->GetDamage();
    }
    target->changeHP(-1 * user->getAttack() * weaponDmg);
}

void EAI::MidLevelAI(Enemy* user, Entity* target) {
    double weaponDmg = 1.0;
    if (user->currentWeapon != nullptr) {
        weaponDmg = user->currentWeapon->GetDamage();
    }
    if (user->getCurrentHp() < (user->getMaxHp() / 2.0)) {
        int64_t healOrDef = randUint() % 3;
        if (healOrDef < 2) {
            for (int i = 0; i < user->Inven.GetUsedElements(); i++) {
                if (user->Inven.GetItem(i)->GetType() == "HEAL") {
                    user->Inven.GetItem(i)->Use(user, std::vector<Entity*>{target});
                    return;
                }
            }
            target->changeHP(-1 * user->getAttack() * weaponDmg);
        } else {
            for (int i = 0; i < user->Inven.GetUsedElements(); i++) {
                if (user->Inven.GetItem(i)->GetType() == "STATUS") {
                    user->Inven.GetItem(i)->Use(user, std::vector<Entity*>{target});
                    return;
                }
            }
            target->changeHP(-1 * user->getAttack() * weaponDmg);
        }
    } else if (user->getAttack() < (target->getAttack() - 15)) {
        for (int i = 0; i < user->Inven.GetUsedElements(); i++) {
            if (user->Inven.GetItem(i)->GetType() == "STATUS") {
                user->Inven.GetItem(i)->Use(user, std::vector<Entity*>{target});
                return;
            }
        }
        target->changeHP(-1 * user->getAttack() * weaponDmg);
    } else {
        if (randBool()) {
            target->changeHP(-1 * user->getAttack() * weaponDmg);
        } else {
            user->Inven.GetItem(randUint() % user->Inven.GetUsedElements());
        }
    }
}

void EAI::HighLevelAI(Enemy* user, Entity* target) {
    double weaponDmg = 1.0;
    if (user->currentWeapon != nullptr) {
        weaponDmg = user->currentWeapon->GetDamage();
    }
    if (user->getCurrentHp() < (user->getMaxHp() / 2.0)) {
        for (int i = 0; i < user->Inven.GetUsedElements(); i++) {
            if (user->Inven.GetItem(i)->GetType() == "HEAL") {
                user->Inven.GetItem(i)->Use(user, std::vector<Entity*>{target});
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
            for (int i = 0; i < user->Inven.GetUsedElements(); i++) {
                if (user->Inven.GetItem(i)->GetType() == "ARMOR") {
                    user->Inven.GetItem(i)->Use(user, std::vector<Entity*>{target});
                    return;
                } 
            }
        }
        int64_t attkOrItem = randUint() % 5;
        if (attkOrItem > 0) {
            target->changeHP(-1 * user->getAttack() * weaponDmg);
        } else {
            user->Inven.GetItem(randUint() % user->Inven.GetUsedElements());
        }
    }
}

void EAI::HealHappy(Enemy* user, Entity* target) {
    double weaponDmg = 1.0;
    if (user->currentWeapon != nullptr) {
        weaponDmg = user->currentWeapon->GetDamage();
    }
    int64_t healChance = randUint() % 3;
    if (healChance < 2) {
        for (int i = 0; i < user->Inven.GetUsedElements(); i++) {
            if (user->Inven.GetItem(i)->GetType() == "HEAL") {
                user->Inven.GetItem(i)->Use(user, std::vector<Entity*>{target});
                return;
            }
        }
        target->changeHP(-1 * user->getAttack() * weaponDmg);
    } else {
        target->changeHP(-1 * user->getAttack() * weaponDmg);
    }
}

void EAI::ItemHappy(Enemy* user, Entity* target) {
    double weaponDmg = 1.0;
    if (user->currentWeapon != nullptr) {
        weaponDmg = user->currentWeapon->GetDamage();
    }
    int64_t invenSize = user->Inven.GetUsedElements();
    if (invenSize > 0) {
        user->Inven.GetItem(randUint() % invenSize);
    } else {
        target->changeHP(-1 * user->getAttack() * weaponDmg);
    }
}