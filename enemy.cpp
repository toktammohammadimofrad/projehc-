#include "Enemy.h"

Enemy::Enemy(int health, int damage, QLabel* label)
    : health(health), damage(damage), label(label) {}

void Enemy::takeDamage(int amount) {
    health -= amount;
    if (health <= 0) {

    }
}

int Enemy::getHealth() const {
    return health;
}

void Enemy::move() {


    QPoint pos = label->pos();
    pos.setY(pos.y() + 1);
    label->move(pos);
}

QLabel* Enemy::getLabel() const {
    return label;
}
