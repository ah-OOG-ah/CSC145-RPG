#pragma once

#include "Enemy.h"
#include "Entity.h"
#include <iostream>
#include "game.h"

void DefaultAI(Enemy* user, Entity* target)
{
    target->changeHP(-1 * user->getAttk());
}

void ItemHappy(Enemy* user, Entity* target)
{
    int64_t invenSize = user->Inven.GetUsedElements();
    if(invenSize > 0)
    {
        user->Inven.GetItem(getRand() % invenSize);
    }
    else
    {
        target->changeHP(-1 * user->getAttk());
    }
}

void higherLevelBehavior(Enemy* user, Entity* target)
{
    int64_t fleeChance = getRand() % 100;
    if(fleeChance <=10)
    {
        //Flee code
    }
    if(user->getCurrentHp() < (user->getMaxHp() / 2.0))
    {
        Item* chosenItem = user->Inven.GetItem(getRand() % user->Inven.GetUsedElements());
        while(chosenItem->GetType() != "HEAL")
        {
            chosenItem = user->Inven.GetItem(getRand() % user->Inven.GetUsedElements());
        }
        chosenItem->Use(user, std::vector<Entity*>{target});
    }
    else if(user->getAttk() < (target->getAttk() - 10))
    {
        Item* chosenItem = user->Inven.GetItem(getRand() % user->Inven.GetUsedElements());
        while(chosenItem->GetType() != "STATUS")
        {
            chosenItem = user->Inven.GetItem(getRand() % user->Inven.GetUsedElements());
        }
        chosenItem->Use(user, std::vector<Entity*>{target});
    }
    else
    {
        target->changeHP(-1 * user->getAttk());
    }
}