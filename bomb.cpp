#include "Bomb.h"

Bomb::Bomb(QLabel* label, QObject* parent)
    : Agent(label, parent) {
    label->setStyleSheet("background-color: black; border: 1px solid black;");
}

void Bomb::move() {

}

void Bomb::shoot() {

}

void Bomb::explode(QVector<Enemy*>& enemies) {
    for (int i = 0; i < std::min(2,static_cast<int>(enemies.size())); ++i) {
        delete enemies[i]->getLabel();
        delete enemies[i];
        enemies.removeAt(i);
    }
}
