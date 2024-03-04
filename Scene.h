#pragma once

#include <string>
class Scene {

  public:
    const std::string name;

    explicit Scene(std::string name);

    virtual void run() = 0;
};
