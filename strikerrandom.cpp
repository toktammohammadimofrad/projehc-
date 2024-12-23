#include "StrikerRandom.h"

StrikerRandom::StrikerRandom(QObject* parent)
    : StrikerBase(parent)
{
}

void StrikerRandom::attack(std::vector<Enemy*>& enemies) {
    if (!enemies.empty()) {

        int randomIndex = QRandomGenerator::global()->bounded(enemies.size());
        enemies[randomIndex]->takeDamage(getDamage());
    }
}
