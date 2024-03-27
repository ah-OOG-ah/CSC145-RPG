#pragma once

#include "Entity.h"
#include "Menu.h"
#include "Player.h"
#include <cstdint>
#include <memory>

class BattleMenu : public Menu {

  public:
    BattleMenu();
    std::shared_ptr<Entity> player;

  protected:
    void dispatch(int64_t i) override;

  private:
    void attack();
    void escape();
};
