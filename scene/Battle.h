#pragma once

#include "Enemy.h"
#include "Entity.h"
#include "Menu.h"
#include "Player.h"
#include "scene/Scene.h"
#include <memory>
#include <vector>
#include <queue>


/**
 * This scene is entered for combat.
 */
class Battle : public Scene, public Menu {

  private:
    const std::function<bool(std::shared_ptr<Entity>, std::shared_ptr<Entity>)> compare = [](auto e, auto e2) { return e->getSpd() > e2->getSpd(); };
    std::vector<std::shared_ptr<Enemy>> enemy;
    //std::vector<std::weak_ptr<Entity>> turnOrder;
    bool over = false;

    void attack();
    static void escape();
    void listEnemies();

  protected:
    void dispatch(int64_t i) override;

  public:
    Battle(std::string, int64_t nice);
    void run() override;
};
