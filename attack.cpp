#include "attack.h"
#include <cstdint>
#include <string>

std::string Attack::GetName() { return attkName; }

int64_t Attack::GetDamage() { return damage; }