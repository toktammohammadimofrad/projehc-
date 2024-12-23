#ifndef STRIKEREND_H
#define STRIKEREND_H

#include "StrikerBase.h"

class StrikerEnd : public StrikerBase {
    Q_OBJECT
public:
    StrikerEnd(QObject* parent = nullptr);
    void attack(std::vector<Enemy*>& enemies) override;
    int getExirCost() const override { return 2; }
    int getDamage() const override { return 15; }
    int getLevel() const override { return 1; }
};

#endif // STRIKEREND_H
