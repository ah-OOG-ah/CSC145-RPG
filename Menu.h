#pragma once

#include <string>
#include <vector>


/**
 * A standard menu interface. Scenes or other classes with a run loop/run method may use it to display a menu.
 * dispatch() converts menu entry numbers to function calls.
 */
class Menu {
  public:
    std::vector<std::string> entries;

    Menu();
    explicit Menu(std::vector<std::string> entries);

    virtual void display();

  protected:
    virtual void dispatch(int64_t i) = 0;
};
