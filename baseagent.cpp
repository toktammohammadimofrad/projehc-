#include "BaseAgent.h"

BaseAgent::BaseAgent(QLabel* label, QObject* parent)
    : QObject(parent), m_label(label), m_health(100), m_level(1) {}

QLabel* BaseAgent::getLabel() const {
    return m_label;
}

int BaseAgent::getHealth() const {
    return m_health;
}

int BaseAgent::getLevel() const {
    return m_level;
}

void BaseAgent::setHealth(int health) {
    m_health = health;
}

void BaseAgent::setLevel(int level) {
    m_level = level;
}
