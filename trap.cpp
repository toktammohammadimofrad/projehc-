#include "Trap.h"

Trap::Trap(QLabel* label, QObject* parent)
    : Agent(label, parent) {
    label->setStyleSheet("background-color: gray; border: 1px solid black;");
}

void Trap::move() {

}

void Trap::shoot() {

}

void Trap::trigger(QVector<Enemy*>& enemies) {
    for (int i = 0; i < std::min(3, static_cast<int>(enemies.size())); ++i) {
        delete enemies[i]->getLabel();
        delete enemies[i];
        enemies.removeAt(i);
    }
}
