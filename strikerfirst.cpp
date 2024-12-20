#include "StrikerFirst.h"
#include <QTimer>

StrikerFirst::StrikerFirst(QLabel* label, QObject* parent)
    : BaseAgent(label, parent) {

    QTimer* timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &StrikerFirst::attack);
    timer->start(1000);
}

void StrikerFirst::move() {

}

void StrikerFirst::attack() {

}
