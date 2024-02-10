#pragma once

#include <cstdint>
#include <string>

class Attack {

  protected:
    std::string attkName;
    int64_t damage;
    
    /*Joseph: Still deciding how to handle additional effects. 
    Should it have a Status pointer for Status effects
    and a seperate pointer or variable for stat boosts? 
    How we handle the stat boost pointer or variable?
    */

  public:
    Attack(std::string name, int64_t dmg);

    std::string GetName();
    int64_t GetDamage();
};