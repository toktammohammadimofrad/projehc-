#include "StrikerMaxHealth.h"
#include <QTimer>

StrikerMaxHealth::StrikerMaxHealth(QLabel* label, QObject* parent)
    : BaseAgent(label, parent) {

    QTimer* timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &StrikerMaxHealth::attack);
    timer->start(1000);
}

void StrikerMaxHealth::move() {

}

void StrikerMaxHealth::attack() {
}
