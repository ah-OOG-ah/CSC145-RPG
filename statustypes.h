#pragma once

#include "Status.h"


namespace stypes {

    void poisonEffect(Entity *victim, Status *ailment);

    void paralyzeEffect(Entity *victim, Status *ailment);

    void sleepEffect(Entity *victim, Status *ailment);

    Status poison("Poison", 4, poisonEffect);
    Status longPoison("Long-Lasting Poison", 8, poisonEffect);
    Status paralysis("Paralysis", 5, paralyzeEffect);
    Status sleep("Sleep", 3, sleepEffect);
}