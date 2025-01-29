#include "StrikerRandom.h"
#include "Enemy.h"
#include <QPainter>
#include <QRandomGenerator>
#include <QList>
#include "mainwindow.h"


StrikerRandom::StrikerRandom(QWidget *parent) : Agent(parent) {
    getLabel()->setText("StrikerRandom");
    m_elixirCost = 4;

    connect(m_shootTimer, &QTimer::timeout, this, [=]() {
        if (!isFrozen()) {

            Enemy* target = findRandomEnemy();
            if (target) {
                m_target = target->pos();
                shoot(target->pos());
                target->takeDamage(30);
            }
        }
    });
}

void StrikerRandom::shootEnemy(Enemy* target) {
    target->takeDamage(30);
}

void StrikerRandom::move() {

}

Enemy* StrikerRandom::findRandomEnemy() {
    QList<Enemy*> enemies = mainWindow->getEnemies();

    if (enemies.isEmpty()) {
        return nullptr;
    }


    int randomIndex = QRandomGenerator::global()->bounded(enemies.size());

    return enemies[randomIndex];
}


void StrikerRandom::paintEvent(QPaintEvent *event) {
    Agent::paintEvent(event);
    QPainter painter(this);
    QPen pen(Qt::red);
    pen.setWidth(3);
    painter.setPen(pen);
    painter.drawLine(this->rect().center(), m_target);
}
