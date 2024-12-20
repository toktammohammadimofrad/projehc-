#include "Enemy.h"

Enemy::Enemy(QLabel* label, QObject* parent)
    : BaseAgent(label, parent), m_speed(0.5f) {}

void Enemy::move() {

    int x = m_label->x();
    int y = m_label->y() + static_cast<int>(m_speed);
    m_label->move(x, y);
}

void Enemy::setType(Type type) {
    m_type = type;
    switch (type) {
    case Soldier:
        m_health = 100;
        m_speed = 0.5f;
        break;
    case BossEraser:
    case BossFreezer:
    case BossDisarmer:
        m_health = 2000;
        m_speed = 0.25f;
        break;
    }
}

Enemy::Type Enemy::getType() const {
    return m_type;
}
