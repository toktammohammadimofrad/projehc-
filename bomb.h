#ifndef BOMB_H
#define BOMB_H

#include "Agent.h"
#include"enemy.h"
#include<Qvector>

class Bomb : public Agent {
    Q_OBJECT
public:
    Bomb(QLabel* label, QObject* parent = nullptr);

    void move() override;
    void shoot() override;

    void explode(QVector<Enemy*>& enemies);
};

#endif
