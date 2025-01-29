#ifndef BLOCKER_H
#define BLOCKER_H

#include "Agent.h"
#include "Enemy.h"

class Blocker : public Agent {
    Q_OBJECT

public:
    explicit Blocker(QWidget *parent = nullptr);
    void shootEnemy(Enemy* target);


};

#endif
