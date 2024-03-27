#pragma once


#include "Floor.h"
#include "Scene.h"

class Tower : public Scene {

  public:
    Tower();

    void pushFloor();
    void run() override;

  private:
    int64_t floorNum = 0;
    Floor* floor = nullptr;
    Floor* history[10] = {};
};
