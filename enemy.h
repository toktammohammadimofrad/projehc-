#ifndef ENEMY_H
#define ENEMY_H

#include <QWidget>
#include <QLabel>
#include <QTimer>

class Enemy : public QWidget {
    Q_OBJECT

public:
    Enemy(QWidget *parent = nullptr);
    void move(int x, int y);
    void takeDamage(int damage);
    int health() const;
    void setHealth(int health);
    bool isInRange(QWidget *widget);
    virtual void specialAbility() = 0;
    void setLabel(const QString &text);
    virtual QWidget* widget();
    virtual void setSpeed(double speed) = 0;
    virtual double speed() const = 0;


protected:
    void paintEvent(QPaintEvent *event) override;



private:
    QLabel *m_label;
    int m_health;
};

#endif
