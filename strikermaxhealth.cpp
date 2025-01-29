#include "StrikerMaxHealth.h"
#include "Enemy.h"
#include <QPainter>
#include <QList>
#include "mainwindow.h"

StrikerMaxHealth::StrikerMaxHealth(QWidget *parent) : Agent(parent) {
    getLabel()->setText("StrikerMaxHealth");
    m_elixirCost = 3;

    connect(m_shootTimer, &QTimer::timeout, this, [=]() {
        if (!isFrozen()) {
            Enemy* target = findMaxHealthEnemy();
            if (target) {
                m_target = target->pos();
                shoot(target->pos());
                target->takeDamage(22.5);
            }
        }
    });
}

void StrikerMaxHealth::shootEnemy(Enemy* target) {
    target->takeDamage(22.5);
}

void StrikerMaxHealth::move() {

}

Enemy* StrikerMaxHealth::findMaxHealthEnemy() {

    QList<Enemy*> enemies = mainWindow->getEnemies();

    if (enemies.isEmpty()) {
        return nullptr;
    }

    Enemy* maxHealthEnemy = nullptr;
    int maxHealth = -1;

    for (Enemy* enemy : enemies) {
        if (enemy && enemy->health() > maxHealth) {
            maxHealthEnemy = enemy;
            maxHealth = enemy->health();
        }
    }

    return maxHealthEnemy;
}

void StrikerMaxHealth::paintEvent(QPaintEvent *event) {
    Agent::paintEvent(event);
    QPainter painter(this);
    QPen pen(Qt::red);
    pen.setWidth(3);
    painter.setPen(pen);
    painter.drawLine(this->rect().center(), m_target);
}
