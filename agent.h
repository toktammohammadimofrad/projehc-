#ifndef AGENT_H
#define AGENT_H

#include <QObject>
#include <QLabel>

class Agent : public QObject {
    Q_OBJECT
public:
    Agent(QLabel* label, QObject* parent = nullptr);

    virtual void move() = 0;
    virtual void shoot() = 0;

    void levelUp();
    void increaseSpeed();

    int getLevel() const;
    QLabel*getLabel()const;

protected:
    QLabel* m_label;
    int m_level;
    int m_cost;
    int m_shootInterval;
    int m_shootCooldown;
};

#endif
