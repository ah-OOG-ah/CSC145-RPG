#include "Enemy.h"
#include "Equipment.h"
#include "game.h"
#include <string>
#include <cstdint>
#include <iostream>
#include <utility>


Enemy::Enemy(const std::string& name, int64_t hp, int64_t attk, double percDef, int64_t staticDef, int64_t spd, const Inventory& inv, const std::shared_ptr<Weapon>& weapon, const ArmorSet& armor, std::array<std::string, 5> sprite, std::vector<std::shared_ptr<Item>> extraLoot, const std::function<void(Enemy*, EquippedEntity*)>& behavior)
    : EquippedEntity(name, hp, attk, percDef, staticDef, spd, inv), extraLoot(std::move(extraLoot)) {
    this->enemySprite = std::move(sprite);
    this->currentWeapon.reset(weapon.get());
    this->armor = armor;
}

Enemy::Enemy(Enemy* en) : EquippedEntity(en) {
    this->enemySprite = en->getSprite();
    this->currentWeapon = en->currentWeapon;
    this->armor = en->armor;
    this->Inven = en->Inven;
    this->extraLoot = en->getExtraLoot();
}

Enemy::Enemy(const std::shared_ptr<Enemy>& en) : EquippedEntity(en.get()) {
    this->enemySprite = en->getSprite();
    this->currentWeapon = en->currentWeapon;
    this->armor = en->armor;
    this->Inven = en->Inven;
    this->extraLoot = en->getExtraLoot();
}

std::array<std::string, 5> Enemy::getSprite() const { return enemySprite; }
std::vector<std::shared_ptr<Item>> Enemy::getExtraLoot() { return extraLoot; }

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
