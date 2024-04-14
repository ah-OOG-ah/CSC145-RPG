#pragma once

#include <string>

/**
 * A standard scene implementation. Pretty much any time in game, the player will be in some Scene's run loop. Children
 * may also implement Menu to provide the interface, but they don't have to - and they can mix in their own messages as
 * well.
 */
class Scene {

  public:
    const std::string name;

    explicit Scene(std::string name);

    virtual void run() = 0;
};
