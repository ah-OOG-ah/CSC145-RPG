#pragma once

#include "BattleMenu.h"
#include "Enemy.h"
#include "Entity.h"
#include "Menu.h"
#include "Player.h"
#include "Scene.h"
#include <memory>
#include <vector>


class Battle : public Scene, public Menu {

  private:
    std::vector<Enemy> enemy;
    std::shared_ptr<Player> player;

    void attack();
    void escape();

  protected:
    void dispatch(int64_t i) override;

  public:
    explicit Battle(std::string);
    void run() override;
};
