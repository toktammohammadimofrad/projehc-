#ifndef STRIKERMAXHEALTH_H
#define STRIKERMAXHEALTH_H

#include "BaseAgent.h"

class StrikerMaxHealth : public BaseAgent {
    Q_OBJECT

public:
    explicit StrikerMaxHealth(QLabel* label, QObject* parent = nullptr);
    void move() override;

private:
    void attack();
};

#endif // STRIKERMAXHEALTH_H
