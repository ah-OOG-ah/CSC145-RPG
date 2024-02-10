#pragma once

#include "BattleMenu.h"
#include "Enemy.h"
#include "Entity.h"
#include "Menu.h"
#include "Player.h"
#include "Scene.h"
#include <memory>
#include <vector>


class Battle : public Scene {

  private:
    std::vector<Enemy> enemy;
    std::shared_ptr<Player> player;
    BattleMenu battleMenu;

  public:
    Battle(std::string);
    virtual void run() override;
};
