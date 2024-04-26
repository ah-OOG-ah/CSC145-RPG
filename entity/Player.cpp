#include "Player.h"
#include <cstdint>

Player::Player(int64_t hp, int64_t x, int64_t y) : EquippedEntity("Player", hp, 40, 1.0, 0, 10), x(x), y(y) {}
