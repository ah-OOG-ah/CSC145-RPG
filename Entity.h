#pragma once

#include <cstdint>
#include <string>
#include "Equipment.h"
#include "inventory.h"
#include <array>

class Entity {

  protected:
    std::string name;
    int64_t hp;
    int64_t attk = 10;
    int64_t percDef = 0; // Reduces a specified percentage of damage from an attack after staticDef removes its amount
    int64_t staticDef = 0; // Subtracts a set amount of damage from a hit
    int64_t spd = 10; // Used to determine turn order
    int64_t mp = 0; // Used to have a magic points system if we want include that
    bool isFleeing = false;

  public:
    Inventory Inven;
    Weapon* currentWeapon;
    std::array<Armor*, 4> armorArray; //Index of arrays are ordered just like ArmorType enum
    //Helmet: 0, Chestplate: 1, Leggings: 2, Boots: 3
    explicit Entity(int64_t hp);
    explicit Entity(std::string name, int64_t hp, int64_t attk, int64_t percDef, int64_t staticDef, int64_t spd);
    Entity(Entity* e);

    [[nodiscard]] std::string getName() const;
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
    void changeAttk(int64_t);
    void changePercDef(int64_t);
    void changeStaticDef(int64_t);
    void changeSpd(int64_t);

    [[nodiscard]] virtual std::string toString() const;
};
