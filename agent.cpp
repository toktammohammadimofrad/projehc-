
#include "Agent.h"

Agent::Agent(QLabel *label, QObject *parent)
    : QObject(parent), m_label(label)
{
    m_animation = new QPropertyAnimation(label, "geometry");
}

Agent::~Agent()
{
    delete m_animation;
}

QLabel* Agent::getLabel() const
{
    return m_label;
}
