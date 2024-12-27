#include "StrikerFirst.h"

StrikerFirst::StrikerFirst(QLabel* label, QObject* parent)
    : Striker(label, 15, parent) {
    label->setStyleSheet("background-color: blue; border: 1px solid black;");
}

void StrikerFirst::targetEnemy(QVector<Enemy*>& enemies) {
    if (!enemies.isEmpty()) {
        enemies.first()->takeDamage(m_hitPower);
    }
}

void StrikerFirst::move() {

}

void StrikerFirst::shoot() {

}
