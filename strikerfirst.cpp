#include "StrikerFirst.h"

StrikerFirst::StrikerFirst(QObject* parent)
    : StrikerBase(parent)
{
}

void StrikerFirst::attack(std::vector<Enemy*>& enemies) {
    if (!enemies.empty()) {

        enemies.front()->takeDamage(getDamage());
    }
}
