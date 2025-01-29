#include "enemy.h"
#include <QPainter>
#include <QPropertyAnimation>
#include <cmath>

Enemy::Enemy(QWidget *parent) : QWidget(parent), m_label(new QLabel(this)), m_health(2000) {
    setFixedSize(40, 40);
}

void Enemy::setLabel(const QString &text) {
    m_label->setText(text);
}

void Enemy::move(int x, int y) {
    qDebug() << "Moving to:" << x << y;
    QPropertyAnimation *animation = new QPropertyAnimation(this, "pos");
    animation->setDuration(500);
    animation->setStartValue(this->pos());
    animation->setEndValue(QPoint(x, y));
    animation->start(QAbstractAnimation::DeleteWhenStopped);
}

void Enemy::takeDamage(int damage) {
    m_health -= damage;
    if (m_health <= 0) {
        delete this;
    }
}

int Enemy::health() const {
    return m_health;
}

void Enemy::setHealth(int health) {
    m_health = health;
}

bool Enemy::isInRange(QWidget *widget) {
    int dx = std::abs(this->x() - widget->x());
    int dy = std::abs(this->y() - widget->y());
    return std::sqrt(dx * dx + dy * dy) <= 100;
}

void Enemy::paintEvent(QPaintEvent *event) {
    Q_UNUSED(event);
    QPainter painter(this);
    painter.setBrush(Qt::red);
    painter.drawEllipse(0, 0, width(), height());
}

QWidget* Enemy::widget()  {
    return nullptr;
}

