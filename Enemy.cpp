#include "Enemy.h"
#include "Equipment.h"
#include "game.h"
#include <string>
#include <cstdint>
#include <iostream>
#include <utility>


Enemy::Enemy(std::string name, int64_t hp, int64_t attk, double percDef, int64_t staticDef, int64_t spd, Inventory inv, const std::shared_ptr<Weapon>& weapon, ArmorSet armor, std::function<void(Enemy*, EquippedEntity*)> behavior )
 : Enemy(std::move(name), hp, attk, percDef, staticDef, spd, inv, weapon, std::move(armor), "", std::move(behavior)) {}
Enemy::Enemy(std::string name, int64_t hp, int64_t attk, double percDef, int64_t staticDef, int64_t spd, Inventory inv, const std::shared_ptr<Weapon>& weapon, ArmorSet armor, std::string sprite, std::function<void(Enemy*, EquippedEntity*)> behavior)
 : EquippedEntity(std::move(name), hp, attk, percDef, staticDef, spd) {
    this->enemySprite = std::move(sprite);
    this->currentWeapon.reset(weapon.get());
    this->armor = std::move(armor);
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

std::string Enemy::getSprite() const { return enemySprite; }
std::vector<Item*> Enemy::getExtraLoot() { return extraLoot; }

std::string Enemy::toString() const {
    if (this->hp > 0)
        return this->getName() + this->getSprite() + "{hp: " + std::to_string(this->hp) + ", atk: " + std::to_string(this->attk) + "}";
    return this -> getName() + "{DEAD, atk: " + std::to_string(this->attk) + "}";
}

std::vector<std::shared_ptr<Item>> Enemy::dropLoot() {
    std::vector<std::shared_ptr<Item>> lootVector;

    for (int i = 0; i < this->Inven.GetUsedElements(); i++) {
        lootVector.emplace_back(this->Inven.GetItem(i));
    }

    for (Item* loot : this->extraLoot) {
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
