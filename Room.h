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

    /*
    Name: GenerateRoom
    Return type: void
    Arguments: 5 int64_t integers
    Use: This function is an abstract function and depends on the derived class implementation. 
    In all implementations it will randomize the room depending on the integers passed in but not all integers will be used
    */
    virtual void GenerateRoom(int64_t ran1, int64_t ran2, int64_t ran3, int64_t ran4, int64_t ran5) = 0;
};