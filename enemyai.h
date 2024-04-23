#pragma once

#include "Enemy.h"
#include "Entity.h"


namespace EAI {

    void DefaultAI(Enemy *user, Entity *target);

    void AttackOnly(Enemy *user, Entity *target);

    void MidLevelAI(Enemy *user, Entity *target);

    void HighLevelAI(Enemy *user, Entity *target);

    void HealHappy(Enemy *user, Entity *target);

    void ItemHappy(Enemy *user, Entity *target);
}