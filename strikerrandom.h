#ifndef STRIKERRANDOM_H
#define STRIKERRANDOM_H

#include "StrikerBase.h"
#include <QRandomGenerator>

class StrikerRandom : public StrikerBase {
    Q_OBJECT
public:
    StrikerRandom(QObject* parent = nullptr);
    void attack(std::vector<Enemy*>& enemies) override;
    int getExirCost() const override { return 4; }
    int getDamage() const override { return 30; }
    int getLevel() const override { return 1; }
    void move()override{}
};

#endif // STRIKERRANDOM_H
