#ifndef TRAP_H
#define TRAP_H

#include "Agent.h"
#include "Enemy.h"
#include "mainwindow.h"

class Trap : public Agent {
    Q_OBJECT

public:
    explicit Trap(QWidget *parent = nullptr);
    void activateTrap();
    MainWindow* mainWindow;


protected:
    void move();
    QList<Enemy*> findNearbyEnemies();
};

#endif
