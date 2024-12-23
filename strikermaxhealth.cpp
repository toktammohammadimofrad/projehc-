#include "StrikerMaxHealth.h"

StrikerMaxHealth::StrikerMaxHealth(QObject* parent)
    : StrikerBase(parent)
{
}

void StrikerMaxHealth::attack(std::vector<Enemy*>& enemies) {
    if (!enemies.empty()) {

        auto maxHealthEnemy = std::max_element(enemies.begin(), enemies.end(),
                                               [](Enemy* a, Enemy* b) { return a->getHealth() < b->getHealth(); });
        (*maxHealthEnemy)->takeDamage(getDamage());
    }
}
