#ifndef BOSS_H
#define BOSS_H

#include "enemy.h"
#include <QTimer>

class Boss : public Enemy {
    Q_OBJECT

public:
    Boss(QWidget *parent = nullptr);
    virtual void specialAbility() = 0;



protected:
    QTimer* abilityTimer;
    int m_health;
    double m_speed;

    void setSpeed(double speed) override;
    double speed() const override;
};

#endif
