#ifndef SOLDIER_H
#define SOLDIER_H

#include "enemy.h"

class Soldier : public Enemy {
    Q_OBJECT

public:
    explicit Soldier(QWidget *parent = nullptr);

    int health() const { return m_health; }
    void setHealth(int health) { m_health = health; }

    virtual void specialAbility() = 0;

protected:
    int m_health;
    double m_speed;
};

#endif // SOLDIER_H
