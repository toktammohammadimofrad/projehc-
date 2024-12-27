#include "Agent.h"

Agent::Agent(QLabel* label, QObject* parent)
    : QObject(parent), m_label(label), m_level(1), m_cost(2), m_shootInterval(3000), m_shootCooldown(0) {}

void Agent::levelUp() {
    ++m_level;
    m_cost *= 2;
    m_shootInterval /= 2;
}

void Agent::increaseSpeed() {
    m_shootInterval /= 2;
}

int Agent::getLevel() const {
    return m_level;
}

QLabel *Agent::getLabel()const {
    return m_label;
}
