#ifndef STRIKER_H
#define STRIKER_H

#include "Agent.h"
#include"enemy.h"
#include<Qvector>

class Striker : public Agent {
    Q_OBJECT
public:
    Striker(QLabel* label, int hitPower, QObject* parent = nullptr);
    virtual void targetEnemy(QVector<Enemy*>& enemies) = 0;

protected:
    int m_hitPower;
};

#endif
