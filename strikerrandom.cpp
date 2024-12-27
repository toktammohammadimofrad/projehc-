#include "StrikerRandom.h"

StrikerRandom::StrikerRandom(QLabel* label, QObject* parent)
    : Striker(label, 30, parent) {
    label->setStyleSheet("background-color: yellow; border: 1px solid black;");
}

void StrikerRandom::targetEnemy(QVector<Enemy*>& enemies) {
    if (!enemies.isEmpty()) {
        int index = QRandomGenerator::global()->bounded(enemies.size());
        enemies[index]->takeDamage(m_hitPower);
    }
}

void StrikerRandom::move() {

}

void StrikerRandom::shoot() {

}
