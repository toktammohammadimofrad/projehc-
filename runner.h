#ifndef RUNNER_H
#define RUNNER_H

#include "soldier.h"

class Runner : public Soldier {
    Q_OBJECT

public:
    explicit Runner(QWidget *parent = nullptr);

    void specialAbility() override;
    void setSpeed(double speed) override;
    double speed() const override;
};

#endif
