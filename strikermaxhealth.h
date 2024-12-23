#ifndef STRIKERMAXHEALTH_H
#define STRIKERMAXHEALTH_H

#include "StrikerBase.h"

class StrikerMaxHealth : public StrikerBase {
    Q_OBJECT
public:
    StrikerMaxHealth(QObject* parent = nullptr);
    void attack(std::vector<Enemy*>& enemies) override;
    int getExirCost() const override { return 3; }
    int getDamage() const override { return 22.5; }
    int getLevel() const override { return 1; }
    void move()override{}
};

#endif // STRIKERMAXHEALTH_H
