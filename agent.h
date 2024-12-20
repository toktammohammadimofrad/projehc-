#ifndef AGENT_H
#define AGENT_H

#include <QObject>
#include <QLabel>

class Agent : public QObject {
    Q_OBJECT
public:
    Agent(QLabel* label, QObject* parent = nullptr);

    void move();
    void shoot();

    QLabel* getLabel() const;
};

#endif // AGENT_H
