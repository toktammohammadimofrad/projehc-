#include "StrikerFirst.h"
#include "Enemy.h"
#include <QPainter>
#include <QList>
#include "mainwindow.h"


StrikerFirst::StrikerFirst(QWidget *parent) : Agent(parent) {
    getLabel()->setText("StrikerFirst");
    m_elixirCost = 2;

    connect(m_shootTimer, &QTimer::timeout, this, [=]() {
        if (!isFrozen()) {

            Enemy* target = findFirstEnemy();
            if (target) {
                m_target = target->pos();
                shoot(target->pos());
                target->takeDamage(15);
            }
        }
    });
}

void StrikerFirst::shootEnemy(Enemy* target) {
    target->takeDamage(15);
}

void StrikerFirst::move() {

}

Enemy* StrikerFirst::findFirstEnemy() {

    QList<Enemy*> enemies = mainWindow->getEnemies();


    if (!enemies.isEmpty()) {

        return enemies.first();
    }

    return nullptr;
}

void StrikerFirst::paintEvent(QPaintEvent *event) {
    Agent::paintEvent(event);
    QPainter painter(this);
    QPen pen(Qt::red);
    pen.setWidth(3);
    painter.setPen(pen);
    painter.drawLine(this->rect().center(), m_target);
}
