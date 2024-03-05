#pragma once

#include <string>
#include "item.h"
#include "Room.h"
#include <cstdint>

class SafeRoom : public Room
{
    protected:
    std::string mapDisplay = "M"; // "M" for Main 
    public:
    void GenerateRoom(int64_t ran1, int64_t ran2, int64_t ran3, int64_t ran4, int64_t ran5) override;
};

class BattleRoom : public Room
{
    protected:
    //SpawnTable
    std::string mapDisplay = "B";
    Item* treasure = nullptr;

    public: 
    Item* GetTreasure();
    void GenerateRoom(int64_t ran1, int64_t ran2, int64_t ran3, int64_t ran4, int64_t ran5) override;
};

class TreasureRoom : public Room
{   
    protected:
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
    protected:
    std::string mapDisplay = "-";

    public:
    void GenerateRoom(int64_t ran1, int64_t ran2, int64_t ran3, int64_t ran4, int64_t ran5) override;
};

class Shop : public Room
{
    protected:
    std::string mapDisplay = "S";
    std::string merchantName;
    Item* purchase1 = nullptr;
    Item* purchase2 = nullptr;
    Item* purchase3 = nullptr;
    /*int64_t price1;
    int64_t price2;
    int64_t price3;*/ //Depending on whether we want each item to determine their own price

    public:
    std::string GetMerchant();
    Item* GetPurchase(int64_t);
    int64_t GetPrice(int64_t);
    void GenerateRoom(int64_t ran1, int64_t ran2, int64_t ran3, int64_t ran4, int64_t ran5) override;
};