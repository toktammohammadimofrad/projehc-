#include "Trap.h"
#include <QTimer>

Trap::Trap(QLabel* label, QObject* parent)
    : BaseAgent(label, parent) {

    QTimer* timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &Trap::trapEnemy);
    timer->start(2000);
}

void Trap::move() {

}

void Trap::trapEnemy() {

}
