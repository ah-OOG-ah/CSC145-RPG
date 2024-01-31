#pragma once

#include "Entity.h"
#include "Scene.h"
#include <memory>
#include <vector>

class Battle : public Scene {

  private:
    std::vector<Entity> enemy;
    std::shared_ptr<Entity> player;

  public:

    virtual ~Battle() override = default;

    virtual void run() override;

};
