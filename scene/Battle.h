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

    void attack();
    static void escape();
    void listEnemies();

  protected:
    void dispatch(int64_t i) override;

  public:
    Battle(std::string, int64_t nice);
    void run() override;
};
