#pragma once

#include "Entity.h"
#include "Player.h"
#include "scene/Scene.h"
#include <memory>


std::shared_ptr<Player> getPlayer();

std::shared_ptr<Scene> getScene();

uint64_t getRand();