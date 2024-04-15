#pragma once

#include <string>
#include <cstdint>
#include <memory>
#include "Movement.h"


class Room {
  protected:
    std::string roomName;
    std::string description;
    std::string mapDisplay = " ";

    bool isExplored = false;
    bool isEntrance = false;
    bool isExit = false;

    std::shared_ptr<Movement> movement = nullptr;

  public:
    Room(std::string name, std::shared_ptr<Movement> m);
    Room(std::string name, std::string description, std::shared_ptr<Movement> m);
    virtual ~Room();

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
};