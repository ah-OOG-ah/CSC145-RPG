#pragma once

#include <functional>
#include <string>

class MenuEntry {

  public:
    const std::string name;
    const std::function<bool(void)> action;

    MenuEntry(std::string name, std::function<bool(void)> action);
};
