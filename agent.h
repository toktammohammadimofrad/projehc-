#ifndef AGENT_H
#define AGENT_H

#include <QObject>
#include <QLabel>
#include <QPropertyAnimation>

class Agent : public QObject
{
    Q_OBJECT

public:
    explicit Agent(QLabel *label, QObject *parent = nullptr);
    virtual ~Agent();
    QLabel* getLabel() const;
    virtual void move() = 0;

protected:
    QLabel *m_label;
    QPropertyAnimation *m_animation;
};

#endif // AGENT_H
