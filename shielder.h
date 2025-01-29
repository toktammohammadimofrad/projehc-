#ifndef SHIELDER_H
#define SHIELDER_H

#include "soldier.h"

class Shielder : public Soldier {
    Q_OBJECT

public:
    explicit Shielder(QWidget *parent = nullptr);

    void specialAbility() override;
    void setSpeed(double speed) override;
    double speed() const override;
};

#endif
