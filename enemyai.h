#pragma once

#include "Enemy.h"
#include "Entity.h"
#include <iostream>
#include "game.h"

void DefaultAI(Enemy* user, Entity* target)
{
    int64_t attkOrItem = getRand() % 2;
    if(attkOrItem == 0)
    {
        double weaponDmg = 1.0;
        if(user->currentWeapon != nullptr)
        {
            weaponDmg = user->currentWeapon->GetDamage();
        }
        target->changeHP(-1 * user->getAttk() * weaponDmg);
    }
    else
    {
        user->Inven.GetItem(getRand() % user->Inven.GetUsedElements());
    }
}

void AttackOnly(Enemy* user, Entity* target)
{
    double weaponDmg = 1.0;
    if(user->currentWeapon != nullptr)
    {
        weaponDmg = user->currentWeapon->GetDamage();
    }
    target->changeHP(-1 * user->getAttk() * weaponDmg);
}

void MidLevelAI(Enemy* user, Entity* target)
{
    double weaponDmg = 1.0;
    if(user->currentWeapon != nullptr)
    {
        weaponDmg = user->currentWeapon->GetDamage();
    }
    int64_t fleeChance = getRand() % 100;
    if(fleeChance <=10)
    {
        //Flee code
    }
    if(user->getCurrentHp() < (user->getMaxHp() / 2.0))
    {
        int64_t healOrDef = getRand() % 3;
        if(healOrDef < 2)
        {
            for(int i = 0; i < user->Inven.GetUsedElements(); i++)
            {
                if(user->Inven.GetItem(i)->GetType() == "HEAL")
                {
                    user->Inven.GetItem(i)->Use(user, std::vector<Entity*>{target});
                    return;
                }
                }
            target->changeHP(-1 * user->getAttk() * weaponDmg);
        }
        else
        {
            for(int i = 0; i < user->Inven.GetUsedElements(); i++)
            {
                if(user->Inven.GetItem(i)->GetType() == "STATUS")
                {
                    user->Inven.GetItem(i)->Use(user, std::vector<Entity*>{target});
                    return;
                }
                }
            target->changeHP(-1 * user->getAttk() * weaponDmg);
        }
    }
    else if(user->getAttk() < (target->getAttk() - 15))
    {
        for(int i = 0; i < user->Inven.GetUsedElements(); i++)
        {
            if(user->Inven.GetItem(i)->GetType() == "STATUS")
            {
                user->Inven.GetItem(i)->Use(user, std::vector<Entity*>{target});
                return;
            }
            
        }
        target->changeHP(-1 * user->getAttk() * weaponDmg);
    }
    else
    {
        int64_t attkOrItem = getRand() % 2;
        if(attkOrItem == 0)
        {
            target->changeHP(-1 * user->getAttk() * weaponDmg);
        }
        else
        {
            user->Inven.GetItem(getRand() % user->Inven.GetUsedElements());
        }
    }
}

void HighLevelAI(Enemy* user, Entity* target)
{
    double weaponDmg = 1.0;
    if(user->currentWeapon != nullptr)
    {
        weaponDmg = user->currentWeapon->GetDamage();
    }
    int64_t fleeChance = getRand() % 100;
    if(fleeChance <=10)
    {
        //Flee code
    }
    if(user->getCurrentHp() < (user->getMaxHp() / 2.0))
    {
        for(int i = 0; i < user->Inven.GetUsedElements(); i++)
        {
            if(user->Inven.GetItem(i)->GetType() == "HEAL")
            {
                user->Inven.GetItem(i)->Use(user, std::vector<Entity*>{target});
                return;
            }
            
        }
        target->changeHP(-1 * user->getAttk() * weaponDmg);
    }
    else if(user->currentWeapon->GetDamage() < (target->currentWeapon->GetDamage()))
    {
        for(int i = 0; i < user->Inven.GetUsedElements(); i++)
        {
            if(user->Inven.GetItem(i)->GetType() == "WEAPON")
            {
                user->Inven.GetItem(i)->Use(user, std::vector<Entity*>{target});
                return;
            } 
        }
        for(int i = 0; i < user->Inven.GetUsedElements(); i++)
        {
            if(user->Inven.GetItem(i)->GetType() == "Status")
            {
                user->Inven.GetItem(i)->Use(user, std::vector<Entity*>{target});
                return;
            } 
        }
        target->changeHP(-1 * user->getAttk() * weaponDmg);
    }
    else
    {
        int64_t armorChoice = getRand() % user->armorArray.size();
        if(user->armorArray[armorChoice]->GetPercDef() < user->armorArray[armorChoice]->GetPercDef() || user->armorArray[armorChoice]->GetStaticDef() < user->armorArray[armorChoice]->GetStaticDef() || user->armorArray[armorChoice]->GetDurab() < 14)
        {
            for(int i = 0; i < user->Inven.GetUsedElements(); i++)
            {
                if(user->Inven.GetItem(i)->GetType() == "ARMOR")
                {
                    user->Inven.GetItem(i)->Use(user, std::vector<Entity*>{target});
                    return;
                } 
            }
        }
        int64_t attkOrItem = getRand() % 5;
        if(attkOrItem > 0)
        {
            target->changeHP(-1 * user->getAttk() * weaponDmg);
        }
        else
        {
            user->Inven.GetItem(getRand() % user->Inven.GetUsedElements());
        }
    }
}

void HealHappy(Enemy* user, Entity* target)
{
    double weaponDmg = 1.0;
    if(user->currentWeapon != nullptr)
    {
        weaponDmg = user->currentWeapon->GetDamage();
    }
    int64_t healChance = getRand() % 3;
    if(healChance < 2)
    {
        for(int i = 0; i < user->Inven.GetUsedElements(); i++)
        {
            if(user->Inven.GetItem(i)->GetType() == "HEAL")
            {
                user->Inven.GetItem(i)->Use(user, std::vector<Entity*>{target});
                return;
            }
        }
        target->changeHP(-1 * user->getAttk() * weaponDmg);
    }
    else
    {
        target->changeHP(-1 * user->getAttk() * weaponDmg);
    }
}

void ItemHappy(Enemy* user, Entity* target)
{
    double weaponDmg = 1.0;
    if(user->currentWeapon != nullptr)
    {
        weaponDmg = user->currentWeapon->GetDamage();
    }
    int64_t invenSize = user->Inven.GetUsedElements();
    if(invenSize > 0)
    {
        user->Inven.GetItem(getRand() % invenSize);
    }
    else
    {
        target->changeHP(-1 * user->getAttk() * weaponDmg);
    }
}

