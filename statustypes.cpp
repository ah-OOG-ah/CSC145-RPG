#include <iostream>
#include "statustypes.h"
#include "game.h"


void stypes::poisonEffect(Entity* victim, Status* ailment) {
    if (ailment->GetRemainingTurns() == 0) {
        //victim->setStatus(nullptr);
        std::cout << victim->getName() << "'s "<< ailment->GetName() << " went away" << std::endl;
        return;
    } else {
        victim->changeHP(-10);
        ailment->ReduceTurn();
        std::cout << victim->getName() << " lost 10 HP due to " << ailment->GetName() << std::endl;
    }
}

void stypes::paralyzeEffect(Entity* victim, Status* ailment) {
    if(ailment->GetRemainingTurns() == 0) {
        //victim->setStatus(nullptr);
        std::cout << victim->getName() << "'s "<< ailment->GetName() << " went away" << std::endl;
        victim->setCanAct(true);
        return;
    } else {
        victim->changeSpd(-10);
        ailment->ReduceTurn();
        int64_t paralyzeChance = getRand() % 3;
        if (paralyzeChance == 2) {
            victim->setCanAct(false);
            std::cout << victim->getName() << " can\'t act due to " << ailment->GetName() << std::endl;
        } else {
            victim->setCanAct(true);
        }
    }
}

void stypes::sleepEffect(Entity* victim, Status* ailment) {
    if (ailment->GetRemainingTurns() == 0) {
        //victim->setStatus(nullptr);
        std::cout << victim->getName() << "'s "<< ailment->GetName() << " went away" << std::endl;
        victim->setCanAct(true);
        return;
    } else {
        ailment->ReduceTurn();
        victim->setCanAct(false);
        std::cout << victim->getName() << " can\'t act due to " << ailment->GetName() << std::endl;
    }
}