#pragma once

#include "Enemy.h"
#include "Entity.h"


namespace EAI {

    void idiot(std::shared_ptr<Enemy> user, std::vector<std::shared_ptr<Enemy>> allies);
    void berserker(std::shared_ptr<Enemy> user, std::vector<std::shared_ptr<Enemy>> allies);
    void amateur(std::shared_ptr<Enemy> user, std::vector<std::shared_ptr<Enemy>> allies);
    void expert(std::shared_ptr<Enemy> user, std::vector<std::shared_ptr<Enemy>> allies);
    void healer(std::shared_ptr<Enemy> user, std::vector<std::shared_ptr<Enemy>> allies);
    void itemHappy(std::shared_ptr<Enemy> user, std::vector<std::shared_ptr<Enemy>> allies);

    static std::function<void(std::shared_ptr<Enemy>,std::vector<std::shared_ptr<Enemy>>)> get(EnumAI);
}