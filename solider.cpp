#include "Soldier.h"

Soldier::Soldier(QLabel* label, QObject* parent)
    : Enemy(label, parent) {
    setType(Enemy::Soldier);
}

void Soldier::move() {
    int x = m_label->x();
    int y = m_label->y() + static_cast<int>(getSpeed());
    m_label->move(x, y);
}
