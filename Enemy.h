#pragma once

#include "Entity.h"

class Enemy : public Entity {
  protected:
  std::string enemySprite;
  public:
    Enemy(std::string name, int64_t hp, int64_t attk, int64_t percDef, int64_t staticDef, int64_t spd);
    Enemy(std::string name, int64_t hp, int64_t attk, int64_t percDef, int64_t staticDef, int64_t spd, std::string sprite);
};
