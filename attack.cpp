#include "attack.h"
#include <cstdint>

Attack::Attack(std::string name, int64_t dmg) {

    this->attkName = name;
    this->damage = dmg;
}

std::string Attack::GetName() {
    return this->attkName;
}

int64_t Attack::GetDamage() {
    return this->damage;
}
