#pragma once

#include "Entity.h"

class Enemy : public Entity {

  public:
    Enemy(int64_t hp) : Entity(hp) {}
};
