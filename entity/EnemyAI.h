#pragma once

#include "Enemy.h"
#include "Entity.h"


namespace EAI {

    void idiot(std::shared_ptr<Enemy> user, std::shared_ptr<EquippedEntity> target);

    void berserker(std::shared_ptr<Enemy> user, std::shared_ptr<EquippedEntity> target);

    void amateur(std::shared_ptr<Enemy> user, std::shared_ptr<EquippedEntity> target);

    void expert(std::shared_ptr<Enemy> user, std::shared_ptr<EquippedEntity> target);

    void healer(std::shared_ptr<Enemy> user, std::shared_ptr<EquippedEntity> target);

    void itemHappy(std::shared_ptr<Enemy> user, std::shared_ptr<EquippedEntity> target);
}