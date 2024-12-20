#ifndef RUNNER_H
#define RUNNER_H

#include "Enemy.h"

class Runner : public Enemy {
    Q_OBJECT

public:
    explicit Runner(QLabel* label, QObject* parent = nullptr);
    void move() override;
};

#endif // RUNNER_H
