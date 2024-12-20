#ifndef BASEAGENT_H
#define BASEAGENT_H

#include <QObject>
#include <QLabel>

class BaseAgent : public QObject {
    Q_OBJECT

public:
    explicit BaseAgent(QLabel* label, QObject* parent = nullptr);
    virtual void move() = 0;
    QLabel* getLabel() const;
    int getHealth() const;
    int getLevel() const;
    void setHealth(int health);
    void setLevel(int level);

protected:
    QLabel* m_label;
    int m_health;
    int m_level;
};

#endif // BASEAGENT_H
