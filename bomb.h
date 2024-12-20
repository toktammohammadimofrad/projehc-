#ifndef BOMB_H
#define BOMB_H

#include "BaseAgent.h"

class Bomb : public BaseAgent {
    Q_OBJECT

public:
    explicit Bomb(QLabel* label, QObject* parent = nullptr);
    void move() override;

private:
    void explode();
};

#endif // BOMB_H
