#ifndef STRIKERFIRST_H
#define STRIKERFIRST_H

#include "Agent.h"
#include "Enemy.h"
#include "mainwindow.h"

class StrikerFirst : public Agent {
    Q_OBJECT

public:
    explicit StrikerFirst(QWidget *parent = nullptr);
    void shootEnemy(Enemy* target);
    MainWindow* mainWindow;

protected:
    void move();
    Enemy* findFirstEnemy();
    void paintEvent(QPaintEvent *event) override;

private:
    QPoint m_target;
};

#endif
