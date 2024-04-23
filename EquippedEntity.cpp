#include "EquippedEntity.h"
#include "Status.h"

Status* EquippedEntity::getStatus() { return this->currentStatus; }

void EquippedEntity::setStatus(Status* ailment) { this->currentStatus = ailment; }