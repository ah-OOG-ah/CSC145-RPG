#pragma once

#include <string>
#include <vector>

class Menu {

  public:
    const std::vector<std::string> entries;

    explicit Menu(std::vector<std::string> entries);

    virtual void display();

  protected:
    virtual void dispatch(int64_t i) = 0;
};
