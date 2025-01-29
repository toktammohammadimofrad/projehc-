#include "runner.h"
#include <QWidget>

Runner::Runner(QWidget *parent) : Soldier(parent) {
    setLabel("Runner");
    setHealth(50);
    m_speed = 1.0f;
}

void Runner::specialAbility() {

}



void Runner::setSpeed(double speed)  {
    m_speed= speed;
}

double Runner::speed() const  {
    return m_speed;
}
