#include "Runner.h"

Runner::Runner(QLabel* label, QObject* parent)
    : Enemy(label, parent) {
    setType(Enemy::Soldier);
    setHealth(50);
    setSpeed(1.0f);
}

void Runner::move() {
    // منطق حرکت دونده
    int x = m_label->x();
    int y = m_label->y() + static_cast<int>(getSpeed());
    m_label->move(x, y);
}
