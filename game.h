#pragma once

#include "entity/Entity.h"
#include "entity/Player.h"
#include "scene/Scene.h"
#include <memory>


std::shared_ptr<Player> getPlayer();
double getPHP();
bool getPFlee();

void setPFlee(bool);

void pAttack(const std::shared_ptr<Entity>&);
void pDisplay();

uint64_t randUint();
int64_t randInt();
bool randBool();

/**
 * Presents the player a management screen. If it returns true, the player has performed an action, usually using an
 * item.
 */
bool manageInventory(const std::vector<std::shared_ptr<Entity>>& enemies, bool& exit);

void saveGame();