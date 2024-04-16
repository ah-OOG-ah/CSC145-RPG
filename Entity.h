#pragma once

#include <cstdint>
#include <string>

class Entity {

  protected:
    int64_t hp;
    int64_t attk = 10;
    int64_t staticDef = 0; // Subtracts a set amount of damage from a hit
    int64_t percDef = 0; // Reduces a specified percentage of damage from an attack after staticDef removes its amount
    int64_t spd = 10; // Used to determine turn order
    int64_t mp = 0; // Used to have a magic points system if we want include that
    bool isFleeing = false;

  public:
    explicit Entity(int64_t hp);

    [[nodiscard]] int64_t getHp() const;
    [[nodiscard]] int64_t getAttk() const;
    [[nodiscard]] int64_t getStaticDef() const;
    [[nodiscard]] int64_t getPercDef() const;
    [[nodiscard]] int64_t getSpd() const;
    [[nodiscard]] int64_t getMp() const;
    [[nodiscard]] bool getFleeing() const;
    [[nodiscard]] bool getAlive() const;

    void setFleeing(bool);

    // Applies this entitiy's attack to the passed entity
    void attackEntity(Entity* enemy) const;

    void changeHP(int64_t hpAmnt); //For item based attacks

    [[nodiscard]] std::string toString() const;
};
