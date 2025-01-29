#include "Trap.h"
#include <QDebug>
#include "mainwindow.h"

Trap::Trap(QWidget *parent) : Agent(parent) {
    getLabel()->setText("Trap");
    m_elixirCost = 2;
}

void Trap::activateTrap() {
    qDebug() << "Trap activated!";

    QList<Enemy*> nearbyEnemies = findNearbyEnemies();
    int targetCount = qMin(2, nearbyEnemies.size());
    for (int i = 0; i < targetCount; ++i) {
        Enemy* enemy = nearbyEnemies.at(i);
        enemy->takeDamage(enemy->health());
    }
}

void Trap::move() {

}

QList<Enemy*> Trap::findNearbyEnemies() {
    QList<Enemy*> nearbyEnemies;

    double detectionRadius = 100.0;

    for (Enemy* enemy : mainWindow->getEnemies()) {
        if (!enemy) continue;


        double enemyX = enemy->x();
        double enemyY = enemy->y();
        double distance = std::sqrt(std::pow(enemyX - this->x(), 2) + std::pow(enemyY - this->y(), 2));


        if (distance <= detectionRadius) {
            nearbyEnemies.append(enemy);
        }
    }

    return nearbyEnemies;
}
