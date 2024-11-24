#include "Agent.h"
#include <QTimer>

Agent::Agent(QLabel* label, QObject* parent)
    : QObject(parent), m_label(label), m_shootInterval(3000), m_shootCooldown(0) {}

void Agent::move() {

}

void Agent::shoot() {

    if (m_shootCooldown <= 0) {

        m_shootCooldown = m_shootInterval;
    } else {
        m_shootCooldown -= 1000;
    }
}

QLabel* Agent::getLabel() const {
    return m_label;
}
