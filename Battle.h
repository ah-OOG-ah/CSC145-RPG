#pragma once

#include "Enemy.h"
#include "Entity.h"
#include "Menu.h"
#include "Scene.h"
#include <memory>
#include <string>
#include <vector>

class Battle : public Scene {

  private:
    std::vector<Enemy> enemy;
    std::shared_ptr<Entity> player;
    Menu battleMenu;

  public:

    Battle(std::string name, Menu menu);
    virtual ~Battle() override = default;

    virtual void run() override;
};
