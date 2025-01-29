#include "shielder.h"
#include <QWidget>

Shielder::Shielder(QWidget *parent) : Soldier(parent) {
    setLabel("Shielder");
    setHealth(100);
    m_speed = 0.5f;
}

void Shielder::specialAbility() {

}


void Shielder::setSpeed(double speed)  {
    m_speed= speed;
}

double Shielder::speed() const {
    return m_speed;
}
