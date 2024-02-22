#pragma once

#include <cstdint>
class Entity {

  protected:
    int64_t hp;
    int64_t attk = 10;
    int64_t staticDef = 0; //Substracts a set amount of damage from a hit
    int64_t percDef = 0; //Reduces a specified percentage of damage from an attack after staticDef removes its amount
    int64_t spd = 10; //Used to determine turn order
    int64_t mp; //Used to have a magic points sytem if we want include that
    bool isFleeing = false;
    bool isAlive = true;

  public:
    Entity(int64_t hp);

    int64_t getHp();
    int64_t getAttk();
    int64_t getStaticDef();
    int64_t getPercDef();
    int64_t getSpd();
    int64_t getMp();
    bool getFleeing();
    bool getAlive();

    void setFleeing(bool);
    void setAlive(bool);
};
