#include "StrikerEnd.h"

StrikerEnd::StrikerEnd(QObject* parent)
    : StrikerBase(parent)
{
}

void StrikerEnd::attack(std::vector<Enemy*>& enemies) {
    if (!enemies.empty()) {

        enemies.back()->takeDamage(getDamage());
    }
}
