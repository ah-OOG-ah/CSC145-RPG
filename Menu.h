#pragma once

#include "MenuEntry.h"
#include <vector>

class Menu {

  public:
    const std::vector<MenuEntry<Menu*>> entries;

    Menu(std::vector<MenuEntry<Menu*>> entries);

    void display();
};
