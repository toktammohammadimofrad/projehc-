#ifndef STRIKERRANDOM_H
#define STRIKERRANDOM_H

#include "Striker.h"
#include <QRandomGenerator>

class StrikerRandom : public Striker {
    Q_OBJECT
public:
    StrikerRandom(QLabel* label, QObject* parent = nullptr);

    void targetEnemy(QVector<Enemy*>& enemies) override;
    void move() override;
    void shoot() override;
};

#endif
