#ifndef ENEMY_H
#define ENEMY_H

#include <QObject>
#include <QLabel>
#include <QPropertyAnimation>

class Enemy : public QObject
{
    Q_OBJECT

public:
    explicit Enemy(QLabel *label, QObject *parent = nullptr);
    virtual ~Enemy();
    QLabel* getLabel() const;
    virtual void move();
    double health() const;
    void reduceHealth(double amount);
    void stopMovement();

protected:
    QLabel *m_label;
    QPropertyAnimation *m_animation;
    double m_health;
};

#endif // ENEMY_H

