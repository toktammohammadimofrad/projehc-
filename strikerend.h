#ifndef STRIKEREND_H
#define STRIKEREND_H

#include "Agent.h"
#include "Enemy.h"
#include "mainwindow.h"

class StrikerEnd : public Agent {
    Q_OBJECT

public:
    explicit StrikerEnd(QWidget *parent = nullptr);
    void shootEnemy(Enemy* target);
    MainWindow* mainWindow;


protected:
    void move();
    Enemy* findLastEnemy();
    void paintEvent(QPaintEvent *event) override;

private:
    QPoint m_target;
};

#endif
