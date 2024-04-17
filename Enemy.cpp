#include "Enemy.h"
#include "Equipment.h"
#include "game.h"
#include <cstdint>
#include <string>

Enemy::Enemy(std::string name, int64_t hp, int64_t attk, int64_t percDef, int64_t staticDef, int64_t spd)
 : Enemy(name, hp, attk, percDef, staticDef, spd, "") {}

Enemy::Enemy(std::string name, int64_t hp, int64_t attk, int64_t percDef, int64_t staticDef, int64_t spd, std::string sprite)
 : Entity(name, hp, attk, percDef, staticDef, spd)
{
    this->enemySprite = sprite;

}