#include "StrikerMaxHealth.h"

StrikerMaxHealth::StrikerMaxHealth(QLabel* label, QObject* parent)
    : Striker(label, 22, parent) {
    label->setStyleSheet("background-color: purple; border: 1px solid black;");
}

void StrikerMaxHealth::targetEnemy(QVector<Enemy*>& enemies) {
    if (!enemies.isEmpty()) {
        auto maxHealthEnemy = std::max_element(enemies.begin(), enemies.end(), [](Enemy* a, Enemy* b) {
            return a->getHealth() < b->getHealth();
        });
        (*maxHealthEnemy)->takeDamage(m_hitPower);
    }
}

void StrikerMaxHealth::move() {

}

void StrikerMaxHealth::shoot() {

}
