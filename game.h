#pragma once

#include "Entity.h"
#include "Player.h"
#include "Scene.h"
#include "Tower.h"
#include <memory>

std::shared_ptr<Player> getPlayer();

std::shared_ptr<Scene> getScene();

int64_t getRand();

int64_t getLevel();

Tower getTower();

void newFloor();

void printExit();
