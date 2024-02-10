#pragma once

#include <string>
class Scene {

  public:
    const std::string name;

    Scene(std::string name);

    virtual void run() = 0;
};
