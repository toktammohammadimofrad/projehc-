#include "Agent.h"
#include <QPainter>
#include <QPen>
#include "enemy.h"

Agent::Agent(QWidget *parent) : QWidget(parent), m_level(1), m_frozen(false), m_elixirCost(0) {
    m_label = new QLabel(this);
    m_label->setAlignment(Qt::AlignCenter);
    m_label->setFixedSize(40, 40);
    setFixedSize(40, 40);

    m_shootTimer = new QTimer(this);
    connect(m_shootTimer, &QTimer::timeout, this, [=]() {

    });
    m_shootTimer->start(1000);
}

void Agent::increaseLevel() {
    ++m_level;
    m_label->setText(QString::number(m_level));
}

QString Agent::getType() const {
    return "Agent";
}

void Agent::setShape(const QString &shape) {
    m_shape = shape;

    if (shape == "circle") {
        m_label->setStyleSheet("background-color: blue; border-radius: 20px;");
    } else if (shape == "triangle") {
        m_label->setStyleSheet("background-color: green; clip-path: polygon(50% 0%, 0% 100%, 100% 100%);");
    } else if (shape == "square") {
        m_label->setStyleSheet("background-color: yellow;");
    } else if (shape == "pentagon") {
        m_label->setStyleSheet("background-color: red; clip-path: polygon(50% 0%, 100% 38%, 82% 100%, 18% 100%, 0% 38%);");
    } else if (shape == "hexagon") {
        m_label->setStyleSheet("background-color: purple; clip-path: polygon(50% 0%, 100% 25%, 100% 75%, 50% 100%, 0% 75%, 0% 25%);");
    }
}

QString Agent::shape() const {
    return m_shape;
}

int Agent::level() const {
    return m_level;
}

int Agent::elixirCost() const {
    return m_elixirCost;
}

QLabel* Agent::getLabel() {
    return m_label;
}

void Agent::setFrozen(bool frozen) {
    m_frozen = frozen;
}

bool Agent::isFrozen() const {
    return m_frozen;
}

void Agent::shoot(QPoint target) {
    QPainter painter(this);
    QPen pen(Qt::red);
    pen.setWidth(3);
    painter.setPen(pen);
    painter.drawLine(this->rect().center(), target);
}



