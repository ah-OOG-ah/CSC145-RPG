#pragma once

#include "game.h"
#include <vector>


template<typename T> struct Util {
    using shp = std::shared_ptr<T>;

    static shp draw(const std::vector<shp>& i) {
        return i[randUint() % i.size()];
    }

    static std::function<std::shared_ptr<T>(void)> drawFactory(const std::vector<shp>& i) {
        return [i]() { return Util<T>::draw(i); };
    }
};

struct UtilI {
    using shpI = std::shared_ptr<Item>;

    static std::vector<shpI> draw(std::initializer_list<const std::vector<shpI>> il, uint64_t num) {
        std::vector<shpI> pool;
        for (const auto& l : il) {
            for (const auto& e : l) {
                pool.push_back(e);
            }
        }

        std::vector<shpI> ret;
        for (uint64_t i = 0; i < num; ++i) {
            ret.emplace_back(pool[randUint() % pool.size()]);
        }
        return ret;
    }

    static std::function<Inventory(void)> drawI(std::initializer_list<const std::vector<shpI>> il, uint64_t num) {
        std::vector<shpI> pool;
        for (const auto& l : il) {
            for (const auto& e : l) {
                pool.push_back(e);
            }
        }
        return [pool, num]() { return Inventory(draw({ pool }, num)); };
    }

    static ArmorSet drawA(const std::vector<std::shared_ptr<Armor>>& a) {
        ArmorSet ret(ITiers::noArmor);
        for (int i = 0; i < 4; ++i)
            ret.set(Util<Armor>::draw(a));
        return ret;
    }

    static std::function<ArmorSet(void)> drawAFactory(const std::vector<std::shared_ptr<Armor>>& a) {
        return [a]() { return drawA(a); };
    }
};