#ifndef TRAP_H
#define TRAP_H

#include "BaseAgent.h"

class Trap : public BaseAgent {
    Q_OBJECT

public:
    explicit Trap(QLabel* label, QObject* parent = nullptr);
    void move() override;

private:
    void trapEnemy();
};

#endif // TRAP_H
