#ifndef STRIKEREND_H
#define STRIKEREND_H

#include "BaseAgent.h"

class StrikerEnd : public BaseAgent {
    Q_OBJECT

public:
    explicit StrikerEnd(QLabel* label, QObject* parent = nullptr);
    void move() override;

private:
    void attack();
};

#endif // STRIKEREND_H
