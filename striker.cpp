#include "Striker.h"

Striker::Striker(QLabel* label, int hitPower, QObject* parent)
    : Agent(label, parent), m_hitPower(hitPower) {}
