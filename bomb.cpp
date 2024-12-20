#include "Bomb.h"
#include <QTimer>

Bomb::Bomb(QLabel* label, QObject* parent)
    : BaseAgent(label, parent) {

    QTimer* timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &Bomb::explode);
    timer->start(2000);
}

void Bomb::move() {

}

void Bomb::explode() {

}
