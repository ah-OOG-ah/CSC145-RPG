#pragma once

#include "entity/Entity.h"
#include "entity/Player.h"
#include "scene/Scene.h"
#include <memory>


std::shared_ptr<Player> getPlayer();
double getPHP(); //Gets player HP
bool getPFlee(); //Gets player isFleeing bool

void setPFlee(bool); //Sets the player isFleeingBool

void pAttack(const std::shared_ptr<Entity>&); //Gets player attack
void pDisplay(); //Displays players stats and such

std::shared_ptr<Scene> getScene();

uint64_t randUint(); //Makes a random unsigned integet
int64_t randInt(); //Makes a random integer
bool randBool(); //Makes a random bool

void saveGame();