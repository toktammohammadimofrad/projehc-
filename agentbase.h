#ifndef AGENTBASE_H
#define AGENTBASE_H

#include <vector>
#include <QObject>
#include<QLabel>
#include "Enemy.h"
class Enemy;
class AgentBase : public QObject {
    Q_OBJECT
public:
    explicit AgentBase(QObject* parent = nullptr)
        : QObject(parent), exirCost(0), damage(0), level(1), speed(1) {}

    virtual void attack(std::vector<Enemy*>& enemies) = 0;
    virtual int getExirCost() const = 0;
    virtual int getDamage() const = 0;
    virtual void upgrade() = 0;
    virtual int getLevel() const = 0;
    virtual void setLevel(int newLevel) { level = newLevel; }
    virtual void merge(AgentBase* other) = 0;
    QLabel*getLabel()const{return label;}
    virtual void move()=0;
protected:
    QLabel*label;
    int exirCost;
    int damage;
    int level;
    int speed;
};

#endif // AGENTBASE_H
