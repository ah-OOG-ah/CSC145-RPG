#pragma once

#include "Entity.h"
#include "Player.h"
#include "scene/Scene.h"
#include <memory>


std::shared_ptr<Player> getPlayer();
int64_t getPHP();
bool getPFlee();

void setPFlee(bool);

void pAttack(std::shared_ptr<Entity>);

std::shared_ptr<Scene> getScene();

uint64_t randUint();
int64_t randInt();
bool randBool();

void saveGame();