#pragma once

#include <string>
#include <cstdint>

class Room
{
    protected:
    std::string roomName;
    std::string description;
    std::string mapDisplay = " ";
    bool isExplored = false;
    bool isEntrance = false;
    bool isExit = false;

    public:
    /*
    Name: GetName
    Return type: string
    Arguments: None
    Use: Returns the roomName member variable
    */
    std::string GetName();
    /*
    Name: GetDesc
    Return type: string
    Arguments: None
    Use: Returns the description member variable
    */
    std::string GetDesc();
    /*
    Name: GetMapDisplay
    Return type: string
    Arguments: None
    Use: Returns the mapDisplay memberVariable
    */
    std::string GetMapDisplay();

    /*
    Name: GenerateRoom
    Return type: void
    Arguments: 5 int64_t integers
    Use: This function is an abstract function and depends on the derived class implementation. 
    In all implementations it will randomize the room depending on the integers passed in but not all integers will be used
    */
    virtual void GenerateRoom(int64_t ran1, int64_t ran2, int64_t ran3, int64_t ran4, int64_t ran5) = 0;
};