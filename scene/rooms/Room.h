#pragma once

#include <string>
#include <cstdint>
#include <memory>
#include <functional>
#include <utility>
#include "Movement.h"
#include "scene/Scene.h"
#include "Menu.h"


struct Direction {
    std::string name;
    std::function<void(std::shared_ptr<Movement>)> func;

    Direction(std::string n, std::function<void(std::shared_ptr<Movement>)> f) : name(std::move(n)), func(std::move(f)) { }
};

class Room : public Menu {
  protected:
    std::string roomName;
    std::string description;
    std::string mapDisplay = " ";
    int64_t nice;

    bool isExplored = false;
    bool isEntrance = false;
    bool isExit = false;

    std::shared_ptr<Movement> movement = nullptr;

    std::vector<std::function<void()>> funcs;

  public:
    Room(std::string name, std::shared_ptr<Movement> m, uint8_t mask, int64_t nice);
    Room(std::string name, std::string description, std::shared_ptr<Movement> m, uint8_t mask, int64_t nice);
    virtual ~Room();

    void dispatch(int64_t i) override;

    /**
     * Some special action specific to the room, e.g. a shop or treasure.
     */
    virtual void specialAction();

    /*
     * Set the movement struct so rooms can pass changes back up to the Floor.
     */
    void setMovement(std::shared_ptr<Movement>);

    /*
    Name: GetName
    Return type: string
    Arguments: None
    Use: Returns the roomName member variable
    */
    [[nodiscard]] std::string GetName() const;
    /*
    Name: GetDesc
    Return type: string
    Arguments: None
    Use: Returns the description member variable
    */
    [[nodiscard]] std::string GetDesc() const;
    /*
    Name: GetMapDisplay
    Return type: string
    Arguments: None
    Use: Returns the mapDisplay memberVariable
    */
    [[nodiscard]] std::string GetMapDisplay() const;

    static const std::vector<Direction> directions;
};