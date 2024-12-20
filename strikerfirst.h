#ifndef STRIKERFIRST_H
#define STRIKERFIRST_H

#include "BaseAgent.h"

class StrikerFirst : public BaseAgent {
    Q_OBJECT

public:
    explicit StrikerFirst(QLabel* label, QObject* parent = nullptr);
    void move() override;

private:
    void attack();
};

#endif // STRIKERFIRST_H
