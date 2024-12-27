#include "Enemy.h"

Enemy::Enemy(QLabel* label, QObject* parent)
    : QObject(parent), m_label(label), m_health(100), m_currentStep(0) {}

void Enemy::move() {

}

void Enemy::takeDamage(int damage) {
    m_health -= damage;
    if (m_health <= 0) {

    }
}

int Enemy::getHealth() const {
    return m_health;
}

QLabel* Enemy::getLabel() const {
    return m_label;
}
