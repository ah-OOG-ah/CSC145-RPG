#pragma once

#include <string>
#include "item.h"
#include "Room.h"
#include <cstdint>

class SafeRoom : public Room
{
    private:
    std::string mapDisplay = "M"; // "M" for Main 
    public:
    void GenerateRoom(int64_t ran1, int64_t ran2, int64_t ran3, int64_t ran4, int64_t ran5) override;
};

class BattleRoom : public Room
{
    private:
    //SpawnTable
    std::string mapDisplay = "B";
    Item* treasure = nullptr;

    public: 
    Item* GetTreasure();
    void GenerateRoom(int64_t ran1, int64_t ran2, int64_t ran3, int64_t ran4, int64_t ran5) override;
};

class TreasureRoom : public Room
{   
    private:
    //SpawnTable
    std::string mapDisplay = "T";
    Item* treasure = nullptr;
    Item* treasure2 = nullptr;

    public:
    Item* GetTreasure();
    Item* GetTreasure2();
    void GenerateRoom(int64_t ran1, int64_t ran2, int64_t ran3, int64_t ran4, int64_t ran5) override;
};


class HallWay : public Room
{   
    private:
    std::string mapDisplay = "-";

    public:
    void GenerateRoom(int64_t ran1, int64_t ran2, int64_t ran3, int64_t ran4, int64_t ran5) override;
};

class Shop : public Room
{
    private:
    std::string mapDisplay = "S";
    std::string merchantName;
    Item* purchase1 = nullptr;
    Item* purchase2 = nullptr;
    Item* purchase3 = nullptr;
};