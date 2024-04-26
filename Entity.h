#pragma once

#include <cstdint>
#include <string>
#include <array>
#include <functional>
#include <memory>


class Entity {

  protected:
    std::string name;
    double maxHp;
    double hp;
    double attack = 10;
    double percDef = 0; // Reduces a specified percentage of damage from an attack after staticDef removes its amount
    double staticDef = 0; // Subtracts a set amount of damage from a hit
    int64_t spd = 10; // Used to determine turn order
    double mp = 0; // Used to have a magic points system if we want include that
    bool isFleeing = false;
    bool canAct = true;

  public:
    
    //Helmet: 0, Chestplate: 1, Leggings: 2, Boots: 3
    explicit Entity(double hp);
    explicit Entity(std::string name, double hp, double attk, double percDef, double staticDef, int64_t spd);
    explicit Entity(Entity* e);

    [[nodiscard]] std::string getName() const;
    [[nodiscard]] double getMaxHp() const;
    [[nodiscard]] double getCurrentHp() const;
    [[nodiscard]] double getAttack() const;
    [[nodiscard]] double getStaticDef() const;
    [[nodiscard]] double getPercDef() const;
    [[nodiscard]] int64_t getSpd() const;
    [[nodiscard]] double getMp() const;
    [[nodiscard]] bool getFleeing() const;
    [[nodiscard]] bool getCanAct() const;
    [[nodiscard]] bool getAlive() const;

    void setFleeing(bool);
    void setCanAct(bool);

    // Applies this entitiy's attack to the passed entity
    virtual void attackEntity(const std::shared_ptr<Entity>& enemy);

    void changeHP(double); //For item based attacks
    void changeAttack(double);
    void changePercDef(double);
    void changeStaticDef(double);
    void changeSpd(int64_t);

    void setSpd(int64_t);

    virtual void takeDamage(double hpAmnt);

    [[nodiscard]] virtual std::string toString() const;

    bool operator> (const Entity& other) const;
};