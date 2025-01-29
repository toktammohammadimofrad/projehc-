#ifndef STRIKERMAXHEALTH_H
#define STRIKERMAXHEALTH_H

#include "Agent.h"
#include "Enemy.h"
#include "mainwindow.h"

class StrikerMaxHealth : public Agent {
    Q_OBJECT

public:
    explicit StrikerMaxHealth(QWidget *parent = nullptr);
    void shootEnemy(Enemy* target);
    MainWindow* mainWindow;

protected:
    void move();
    Enemy* findMaxHealthEnemy();
    void paintEvent(QPaintEvent *event) override;

private:
    QPoint m_target;
};

#endif
