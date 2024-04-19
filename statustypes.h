#pragma once

#include <iostream>
#include "Status.h"

void poisonStatus(Entity* victim, Status* ailment)
{
    if(ailment->GetTurn() == 0)
    {
        //Set victim's status to nullptr
        return;
    }
    else {
        victim->changeHP(-10);
        ailment->ReduceTurn();
        std::cout << victim->getName() << " lost 10 HP due to the poison " << std::endl;
    }
}

void paralyzeStatus(Entity* victim, Status* ailment)
{
    if(ailment->GetTurn() == 0)
    {
        return;
    }
    else {
        victim->changeHP(-10);
        ailment->ReduceTurn();
        std::cout << victim->getName() << " lost 10 HP due to the poison " << std::endl;
    }
}