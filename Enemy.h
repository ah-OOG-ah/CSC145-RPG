#pragma once

#include "EquippedEntity.h"
#include <vector>
#include "itemtiers.h"


class Enemy : public EquippedEntity {
  protected:
    std::function<void(Enemy*, EquippedEntity*)> behaviorFunction;
    std::string enemySprite;
    std::vector<Item*> extraLoot;

  public:
    Enemy(std::string name, int64_t hp, int64_t attk, double percDef, int64_t staticDef, int64_t spd, std::vector<AttackItem> attkSlots, std::vector<HealItem> healSlots, std::vector<StatusItem> statusSlots, std::vector<Weapon*> weaponSlots, std::vector<Armor*> armorSlots, std::function<void(Enemy*, EquippedEntity*)> behavior );
    Enemy(std::string name, int64_t hp, int64_t attk, double percDef, int64_t staticDef, int64_t spd, std::vector<AttackItem> attkSlots, std::vector<HealItem> healSlots, std::vector<StatusItem> statusSlots, std::vector<Weapon*> weaponSlots, std::vector<Armor*> armorSlots, std::string sprite, std::function<void(Enemy*, EquippedEntity*)> behavior);
    Enemy(std::string name, int64_t hp, int64_t attk, double percDef, int64_t staticDef, int64_t spd, std::vector<AttackItem> attkSlots, std::vector<HealItem> healSlots, std::vector<StatusItem> statusSlots, std::vector<Weapon*> weaponSlots, std::vector<Armor*> armorSlots, std::vector<Item*> extraLoot, std::function<void(Enemy*, EquippedEntity*)> behavior);
    Enemy(std::string name, int64_t hp, int64_t attk, double percDef, int64_t staticDef, int64_t spd, std::vector<AttackItem> attkSlots, std::vector<HealItem> healSlots, std::vector<StatusItem> statusSlots, std::vector<Weapon*> weaponSlots, std::vector<Armor*> armorSlots, std::vector<Item*> extraLoot, std::string sprite, std::function<void(Enemy*, EquippedEntity*)> behavior);
    Enemy(Enemy* en);
    [[nodiscard]] std::string getSprite() const;
    [[nodiscard]] std::vector<Item*> getExtraLoot();
    [[nodiscard]] std::string toString() const override;
    void dropLoot(EquippedEntity* player);
    void attackEntity(EquippedEntity*);
};
