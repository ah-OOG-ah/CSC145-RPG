#include "Player.h"
#include <cstdint>


// TODO: remove invincibility
Player::Player(double hp, int64_t x, int64_t y) : EquippedEntity("Player", hp, 40, 0.0, 0, 10), x(x), y(y) {}
