#ifndef TRAP_H
#define TRAP_H

#include "Agent.h"
#include"enemy.h"
#include<Qvector>

class Trap : public Agent {
    Q_OBJECT
public:
    Trap(QLabel* label, QObject* parent = nullptr);

    void move() override;
    void shoot() override;

    void trigger(QVector<Enemy*>& enemies);
};

#endif
