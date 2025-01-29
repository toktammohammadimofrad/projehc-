#ifndef BOMB_H
#define BOMB_H

#include "Agent.h"
#include "Enemy.h"
#include "mainwindow.h"

class Bomb : public Agent {
    Q_OBJECT

public:
    explicit Bomb(QWidget *parent = nullptr);
    void explode();
    MainWindow* mainWindow;


protected:
    void move();
    QList<Enemy*> findNearbyEnemies();
};

#endif
