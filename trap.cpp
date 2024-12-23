#include "Trap.h"

Trap::Trap(QObject* parent)
    : AgentBase(parent)
{
    damage = 100;
    exirCost = 2;
    level = 1;
    speed = 1;
}

void Trap::attack(std::vector<Enemy*>& enemies) {
    if (!enemies.empty()) {

        for (int i = 0; i < 2 && !enemies.empty(); ++i) {
            enemies.front()->takeDamage(getDamage());
            enemies.erase(enemies.begin());
        }
    }
}
