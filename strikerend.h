#ifndef STRIKEREND_H
#define STRIKEREND_H

#include "Striker.h"

class StrikerEnd : public Striker {
    Q_OBJECT
public:
    StrikerEnd(QLabel* label, QObject* parent = nullptr);

    void targetEnemy(QVector<Enemy*>& enemies) override;
    void move()override;
    void shoot()override;
};

#endif
