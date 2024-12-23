#ifndef BOMB_H
#define BOMB_H

#include "AgentBase.h"

class Bomb : public AgentBase {
    Q_OBJECT
public:
    Bomb(QObject* parent = nullptr);
    void attack(std::vector<Enemy*>& enemies) override;
    int getExirCost() const override { return 2; }
    int getDamage() const override { return 100; }
    int getLevel() const override { return 1; }
    void upgrade() override {
        if (level < 5) {
            level++;

        }
    }
    void merge(AgentBase* other) override {  }
};

#endif // BOMB_H
