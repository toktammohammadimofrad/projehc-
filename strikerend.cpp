#include "StrikerEnd.h"
#include "Enemy.h"
#include <QPainter>
#include <QList>
#include "mainwindow.h"

StrikerEnd::StrikerEnd(QWidget *parent) : Agent(parent) {
    getLabel()->setText("StrikerEnd");
    m_elixirCost = 2;

    connect(m_shootTimer, &QTimer::timeout, this, [=]() {
        if (!isFrozen()) {

            Enemy* target = findLastEnemy();
            if (target) {
                m_target = target->pos();
                shoot(target->pos());
                target->takeDamage(15);
            }
        }
    });
}

void StrikerEnd::shootEnemy(Enemy* target) {
    target->takeDamage(15);
}

void StrikerEnd::move() {

}

Enemy* StrikerEnd::findLastEnemy() {
    QList<Enemy*> enemies = mainWindow->getEnemies();


    if (!enemies.isEmpty()) {

        return enemies.last();
    }

    return nullptr;
}

void StrikerEnd::paintEvent(QPaintEvent *event) {
    Agent::paintEvent(event);
    QPainter painter(this);
    QPen pen(Qt::red);
    pen.setWidth(3);
    painter.setPen(pen);
    painter.drawLine(this->rect().center(), m_target);
}
