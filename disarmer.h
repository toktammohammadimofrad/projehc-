#ifndef DISARMER_H
#define DISARMER_H

#include "boss.h"

class Disarmer : public Boss {
    Q_OBJECT
    QLabel* bossWidget;
public:
    Disarmer(QWidget *parent = nullptr);
    QWidget* widget() override {
        return bossWidget;
    }
    void specialAbility() override;
};

#endif
