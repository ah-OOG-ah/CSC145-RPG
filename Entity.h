#pragma once

#include <cstdint>
#include <string>
#include <array>

class Entity {

  protected:
    std::string name;
    int64_t maxHp;
    int64_t hp;
    double attk = 10;
    double percDef = 0; // Reduces a specified percentage of damage from an attack after staticDef removes its amount
    int64_t staticDef = 0; // Subtracts a set amount of damage from a hit
    int64_t spd = 10; // Used to determine turn order
    int64_t mp = 0; // Used to have a magic points system if we want include that
    bool isFleeing = false;
    bool canAct = true;

  public:
    
    //Helmet: 0, Chestplate: 1, Leggings: 2, Boots: 3
    explicit Entity(int64_t hp);
    explicit Entity(std::string name, int64_t hp, int64_t attk, double percDef, int64_t staticDef, int64_t spd);
    Entity(Entity* e);

    [[nodiscard]] std::string getName() const;
    [[nodiscard]] int64_t getMaxHp() const;
    [[nodiscard]] int64_t getCurrentHp() const;
    [[nodiscard]] double getAttk() const;
    [[nodiscard]] int64_t getStaticDef() const;
    [[nodiscard]] double getPercDef() const;
    [[nodiscard]] int64_t getSpd() const;
    [[nodiscard]] int64_t getMp() const;
    [[nodiscard]] bool getFleeing() const;
    [[nodiscard]] bool getCanAct() const;
    [[nodiscard]] bool getAlive() const;

    void setFleeing(bool);
    void setCanAct(bool);

    // Applies this entitiy's attack to the passed entity
    virtual void attackEntity(Entity* enemy);

    void changeHP(int64_t hpAmnt); //For item based attacks
    void changeAttk(double);
    void changePercDef(double);
    void changeStaticDef(int64_t);
    void changeSpd(int64_t);

    [[nodiscard]] virtual std::string toString() const;
};
