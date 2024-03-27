#pragma once

#include "Menu/Menu.h"
#include "Floor.h"
#include "Scene.h"

class StartMenu : public Menu {

public:
    StartMenu();
    ~StartMenu();

protected:
    void dispatch(int64_t i) override;

private:
    Floor* floor = nullptr;

    void enterTower();
};
