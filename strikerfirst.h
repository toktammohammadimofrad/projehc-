#ifndef STRIKERFIRST_H
#define STRIKERFIRST_H

#include "Striker.h"

class StrikerFirst : public Striker {
    Q_OBJECT
public:
    StrikerFirst(QLabel* label, QObject* parent = nullptr);

    void targetEnemy(QVector<Enemy*>& enemies) override;
    void move()override;
    void shoot()override;
};

#endif
