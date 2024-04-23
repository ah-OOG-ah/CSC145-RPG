#pragma once

#include "Enemy.h"
#include "Entity.h"
#include "Menu.h"
#include "Player.h"
#include "scene/Scene.h"
#include <memory>
#include <vector>


/**
 * This scene is entered for combat.
 */
class Battle : public Scene, public Menu {

  private:
    std::vector<Enemy> enemy;
    std::shared_ptr<Player> player;

    void attack();
    void escape();
    void listEnemies();

  protected:
    void dispatch(int64_t i) override;

  public:
    explicit Battle(std::string, int64_t nice);
    void run() override;
};
