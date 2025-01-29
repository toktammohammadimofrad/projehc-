#ifndef STRIKERRANDOM_H
#define STRIKERRANDOM_H

#include "Agent.h"
#include "Enemy.h"
#include "mainwindow.h"

class StrikerRandom : public Agent {
    Q_OBJECT

public:
    explicit StrikerRandom(QWidget *parent = nullptr);
    void shootEnemy(Enemy* target);
    MainWindow* mainWindow;

protected:
    void move();
    Enemy* findRandomEnemy();
    void paintEvent(QPaintEvent *event) override;

private:
    QPoint m_target;
};

#endif
