#include "Enemy.h"

Enemy::Enemy(QLabel *label, QObject *parent)
    : QObject(parent), m_label(label), m_health(100) // Example health value
{
    m_animation = new QPropertyAnimation(label, "geometry");
}

Enemy::~Enemy()
{
    delete m_animation;
}

QLabel* Enemy::getLabel() const
{
    return m_label;
}

void Enemy::move()
{
    // Example movement logic
    // You can implement the logic based on your specific requirements
}

double Enemy::health() const
{
    return m_health;
}

void Enemy::reduceHealth(double amount)
{
    m_health -= amount;
}

void Enemy::stopMovement()
{
    m_animation->stop();
}
