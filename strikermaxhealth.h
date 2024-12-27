#ifndef STRIKERMAXHEALTH_H
#define STRIKERMAXHEALTH_H

#include "Striker.h"
#include <algorithm>

class StrikerMaxHealth : public Striker {
    Q_OBJECT
public:
    StrikerMaxHealth(QLabel* label, QObject* parent = nullptr);

    void targetEnemy(QVector<Enemy*>& enemies) override;
    void move() override;
    void shoot() override;
};

#endif
