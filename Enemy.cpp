#include "Enemy.h"
#include "Equipment.h"
#include "game.h"
#include <string>
#include <cstdint>
#include <iostream>
#include <utility>


Enemy::Enemy(const std::string& name, double hp, double attk, double percDef, double staticDef, int64_t spd, std::array<std::string, 5> sprite, std::vector<std::shared_ptr<Item>> extraLoot, const std::function<void(Enemy*, EquippedEntity*)>& behavior)
    : EquippedEntity(name, hp, attk, percDef, staticDef, spd, {}), extraLoot(std::move(extraLoot)) {
    // , const Inventory& inv, const std::shared_ptr<Weapon>& weapon, const ArmorSet& armor
    this->enemySprite = std::move(sprite);
    this->currentWeapon.reset();
    this->armor = armor;
}

std::array<std::string, 5> Enemy::getSprite() const { return enemySprite; }
std::vector<std::shared_ptr<Item>> Enemy::getExtraLoot() const { return extraLoot; }

std::vector<std::shared_ptr<Item>> Enemy::dropLoot() {
    std::vector<std::shared_ptr<Item>> lootVector;

    for (size_t i = 0; i < this->Inven.GetUsedElements(); i++) {
        lootVector.emplace_back(this->Inven.GetItem(i));
    }

    for (const auto& loot : this->extraLoot) {
        lootVector.emplace_back(loot);
    }

    for (int i = 0; i < 4; ++i) {
        lootVector.push_back(armor.get(i));
    }

    lootVector.push_back(this->currentWeapon);
    size_t amntOfLoot = randUint() % 4 + 1; // Gives loot 1 to 4
    if (lootVector.size() > amntOfLoot)
        lootVector.erase(std::next(lootVector.begin(), amntOfLoot), lootVector.end());

    std::cout << this->name << " dropped ";
    for (size_t j = 0; j < amntOfLoot; j++) {
        auto pos = randUint() % lootVector.size();
        if (lootVector[pos] == nullptr) continue;
        std::cout << " a(n) " << lootVector[pos]->GetName() << std::endl;
    }

    return lootVector;
}
