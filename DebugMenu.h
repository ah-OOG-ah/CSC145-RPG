#pragma once

#include "Menu.h"
#include <cstdint>

class DebugMenu : public Menu {

  public:
    DebugMenu();

  protected:
    virtual void dispatch(int64_t i) override;

  private:
    void returnToOverworld();
    void enterBattle();
    void manageInventory();
    void enterShop();
    void chat();
    void quitGame();
};
