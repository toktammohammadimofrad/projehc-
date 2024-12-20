#ifndef STRIKERRANDOM_H
#define STRIKERRANDOM_H

#include "BaseAgent.h"

class StrikerRandom : public BaseAgent {
    Q_OBJECT

public:
    explicit StrikerRandom(QLabel* label, QObject* parent = nullptr);
    void move() override;

private:
    void attack();
};

#endif // STRIKERRANDOM_H
