#pragma once

#include "entity/Entity.h"
#include "entity/Player.h"
#include "scene/Scene.h"
#include <memory>


std::shared_ptr<Player> getPlayer();
int64_t getPHP();
bool getPFlee();

void setPFlee(bool);

void pAttack(const std::shared_ptr<Entity>&);
void pDisplay();

std::shared_ptr<Scene> getScene();

uint64_t randUint();
int64_t randInt();
bool randBool();

void saveGame();