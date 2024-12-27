#include "StrikerEnd.h"

StrikerEnd::StrikerEnd(QLabel* label, QObject* parent)
    : Striker(label, 15, parent) {
    label->setStyleSheet("background-color: green; border: 1px solid black;");
}

void StrikerEnd::targetEnemy(QVector<Enemy*>& enemies) {
    if (!enemies.isEmpty()) {
        enemies.last()->takeDamage(m_hitPower);
    }
}

void StrikerEnd::move() {

}

void StrikerEnd::shoot() {

}
