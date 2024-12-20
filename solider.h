#ifndef SOLDIER_H
#define SOLDIER_H

#include "Enemy.h"

class Soldier : public Enemy {
    Q_OBJECT

public:
    explicit Soldier(QLabel* label, QObject* parent = nullptr);
    void move() override;
};

#endif // SOLDIER_H
