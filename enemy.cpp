#include "Enemy.h"

Enemy::Enemy(QLabel* label, QObject* parent)
    : QObject(parent), m_label(label), m_currentStep(0) {

    m_path.append(QPoint(0, 0));
    m_path.append(QPoint(1, 0));
    m_path.append(QPoint(2, 0));
    m_path.append(QPoint(3, 0));
    m_path.append(QPoint(4, 0));
    m_path.append(QPoint(4, 1));
    m_path.append(QPoint(4, 2));
    m_path.append(QPoint(4, 3));
    m_path.append(QPoint(4, 4));
    m_path.append(QPoint(3, 4));
    m_path.append(QPoint(2, 4));
    m_path.append(QPoint(1, 4));
    m_path.append(QPoint(0, 4));
}

void Enemy::move() {
    if (m_currentStep < m_path.size()) {
        QPoint nextPosition = m_path[m_currentStep];
        m_label->setGeometry(nextPosition.x() * m_label->width(), nextPosition.y() * m_label->height(), m_label->width(), m_label->height());
        m_currentStep++;
    }
}

QLabel* Enemy::getLabel() const {
    return m_label;
}
