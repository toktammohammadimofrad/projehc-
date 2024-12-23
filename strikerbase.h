#ifndef STRIKERBASE_H
#define STRIKERBASE_H

#include "AgentBase.h"
#include "Enemy.h"

class StrikerBase : public AgentBase {
    Q_OBJECT
public:
    StrikerBase(QObject* parent = nullptr);
    virtual void attack(std::vector<Enemy*>& enemies) override = 0;
    void upgrade() override {
        if (level < 5) {
            level++;
            damage *= 2;
        }
    }
    void merge(AgentBase* other) override {
        if (other && level == other->getLevel() && typeid(*this) == typeid(*other)) {
            speed *= 2;
            other->deleteLater();
        }
    }

protected:
    int attackInterval;
};

#endif // STRIKERBASE_H
