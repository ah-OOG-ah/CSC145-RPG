#pragma once

#include <cstdint>
class Entity {

  protected:
    int64_t hp;
    int64_t attk = 10;
    int64_t staticDef = 0; //Substracts a set amount of damage from a hit
    int64_t percDef = 0; //Reduces a specified percentage of damage from an attack after staticDef removes its amount
    int64_t spd = 10;
    bool isFleeing = false;

    /*Joseph: Are these x and y variavles for position? I think Tyler just used the position as an example, 
    as position does not make sense in turn-based combat*/

  public:
    Entity(int64_t hp);

    int64_t getHp();
    int64_t getAttk();
    int64_t getStaticDef();
    int64_t getPercDef();
    int64_t getSpd();
    bool getFleeing();

    void setFleeing(bool);
};
