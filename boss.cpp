#include "boss.h"
#include "MainWindow.h"
#include <QTimer>

Boss::Boss(QWidget *parent) : Enemy(parent), m_health(2000),m_speed(0.25f) {
    abilityTimer = new QTimer(this);
    connect(abilityTimer, &QTimer::timeout, this, &Boss::specialAbility);
    abilityTimer->start(7000);
}



void Boss::setSpeed(double speed)  {
    m_speed= speed;
}

double Boss::speed() const  {
    return m_speed;
}
