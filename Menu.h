#pragma once

#include "MenuEntry.h"
#include <vector>

class Menu {
  
  public:
    const std::vector<MenuEntry> entries;

    Menu(std::vector<MenuEntry> entries);

    bool display();
};
