#ifndef TRAP_H
#define TRAP_H

#include "AgentBase.h"

class Trap : public AgentBase {
    Q_OBJECT
public:
    Trap(QObject* parent = nullptr);
    void attack(std::vector<Enemy*>& enemies) override;
    int getExirCost() const override { return 2; }
    int getDamage() const override { return 100; }
    int getLevel() const override { return 1; }
    void upgrade() override {
        if (level < 5) {
            level++;

        }
    }
    void merge(AgentBase* other) override {}
};

#endif // TRAP_H
