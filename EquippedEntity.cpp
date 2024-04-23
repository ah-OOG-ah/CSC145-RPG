#include "EquippedEntity.h"

#include <utility>
#include "Status.h"


EquippedEntity::EquippedEntity(std::string name, int64_t hp, int64_t attk, double percDef, int64_t staticDef, int64_t spd)
    : Entity(std::move(name), hp, attk, percDef, staticDef, spd) {}
EquippedEntity::EquippedEntity(Entity *e) : Entity(e) {}

Status* EquippedEntity::getStatus() { return this->currentStatus; }

void EquippedEntity::setStatus(Status* ailment) { this->currentStatus = ailment; }
