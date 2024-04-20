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
    if(user->getCurrentHp() < (user->getMaxHp() / 2.0) || user->getAttk() < (target->getAttk() - 10))
    {
        user->Inven.GetItem(getRand() % user->Inven.GetUsedElements())->Use(user, std::vector<Entity*>{target});
    }
    else
    {
        target->changeHP(-1 * user->getAttk());
    }
}