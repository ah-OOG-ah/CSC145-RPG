#include "Player.h"
#include <cstdint>

Player::Player(int64_t hp) : Entity(hp) {}

Player::Player(int64_t hp, int64_t x, int64_t y) : Entity(hp), x(x), y(y) {}
