#ifndef AGENT_H
#define AGENT_H

#include <QWidget>
#include <QLabel>
#include <QTimer>
#include <QVector>
#include "enemy.h"

class Agent : public QWidget {
    Q_OBJECT

public:
    explicit Agent(QWidget *parent = nullptr);
    void increaseLevel();
    QString getType() const;
    void setShape(const QString &shape);
    QString shape() const;
    int level() const;
    int elixirCost() const;
    QLabel* getLabel();
    void setFrozen(bool frozen);
    bool isFrozen() const;
    void shoot(QPoint target);
    int m_elixirCost;

protected:

    QTimer *m_shootTimer;

private:
    QLabel *m_label;
    QString m_shape;
    int m_level;
    bool m_frozen;
};

#endif
