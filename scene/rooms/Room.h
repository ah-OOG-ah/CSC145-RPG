#pragma once

#include <string>
#include <cstdint>

class Room {
  protected:
    std::string roomName;
    std::string description;
    std::string mapDisplay = " ";
    bool isExplored = false;
    bool isEntrance = false;
    bool isExit = false;

  public:
    Room(std::string name);
    Room(std::string name, std::string description);
    virtual ~Room();

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