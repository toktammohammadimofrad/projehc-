#include "StrikerRandom.h"
#include <QTimer>
#include <QRandomGenerator>

StrikerRandom::StrikerRandom(QLabel* label, QObject* parent)
    : BaseAgent(label, parent) {

    QTimer* timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &StrikerRandom::attack);
    timer->start(1000);
}

void StrikerRandom::move() {

}

void StrikerRandom::attack() {
}
