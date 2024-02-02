#pragma once

#include <functional>
#include <string>

template<typename T> class MenuEntry {

  public:
    const std::string name;
    const std::function<void(T)> action;

    MenuEntry<T>(std::string name, std::function<void(T)> action): name(name), action(action) {};
};
