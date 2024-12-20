#include "StrikerEnd.h"
#include <QTimer>

StrikerEnd::StrikerEnd(QLabel* label, QObject* parent)
    : BaseAgent(label, parent) {

    QTimer* timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &StrikerEnd::attack);
    timer->start(1000);
}

void StrikerEnd::move() {

}

void StrikerEnd::attack() {


}
