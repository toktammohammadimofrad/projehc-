#ifndef STRIKERFIRST_H
#define STRIKERFIRST_H

#include "StrikerBase.h"

class StrikerFirst : public StrikerBase {
    Q_OBJECT
public:
    StrikerFirst(QObject* parent = nullptr);
    void attack(std::vector<Enemy*>& enemies) override;
    int getExirCost() const override { return 2; }
    int getDamage() const override { return 15; }
    int getLevel() const override { return 1; }
    void move() override {

    }
};

#endif // STRIKERFIRST_H
