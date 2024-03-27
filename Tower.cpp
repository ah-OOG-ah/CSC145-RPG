#include <iostream>
#include "Tower.h"

void Tower::pushFloor() {

    if (this->floor != nullptr) {

        this->history[this->floorNum] = this->floor;
        ++this->floorNum;
    }

    this->floor = new Floor(this->floorNum);
}

Tower::Tower() : Scene("The Tower of Npolfz Cpc") {}

void Tower::run() {

    /**
     * The main run loop.
     * 1. Enter the first floor. Run it
     */

    if (this->floor == nullptr) {
        std::cerr << "Unexpected state: no floor present!" << std::endl;
        std::cerr << "Quitting!" << std::endl;
        return;
    }

    this->floor->run();
}
