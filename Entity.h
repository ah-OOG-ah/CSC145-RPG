#pragma once

#include <cstdint>
class Entity {

  protected:
    int64_t hp;
    int64_t x; 
    int64_t y;
    int64_t attk;
    int64_t staticDef; //Substracts a set amount of damage from a hit
    int64_t percDef; //Reduces a specified percentage of damage from an attack after staticDef removes its amount
    int64_t spd;

    /*Joseph: Are these x and y variavles for position? I think Tyler just used the position as an example, 
    as position does not make sense in turn-based combat*/

  public:
    Entity(int64_t hp);
    Entity(int64_t hp, int64_t x, int64_t y);

    int64_t getHp();
    int64_t getX();
    int64_t getY();
    int64_t getAttk();
    int64_t getStaticDef();
    int64_t getPercDef();
    int64_t getSpd();
};

class Player : public Entity
{
    Player(int64_t hp) : Entity(hp);
    Player(int64_t hp, int64_t x, int64_t y) : Entity(hp, x, y);
};

class Enemy : public Entity
{
    Enemy(int64_t hp) : Entity(hp);
    Enemy(int64_t hp, int64_t x, int64_t y) : Entity(hp, x, y);
};