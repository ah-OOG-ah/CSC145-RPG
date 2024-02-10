#include "Player.h"
#include "attack.h"
#include <cstdint>

Player::Player(int64_t hp) : Entity(hp), attack("A standard attack", 10) {}

Player::Player(int64_t hp, int64_t x, int64_t y) : Entity(hp), x(x), y(y), attack("A standard attack", 10) {}
