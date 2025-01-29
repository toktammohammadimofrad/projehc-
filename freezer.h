#ifndef FREEZER_H
#define FREEZER_H

#include "boss.h"
#include "agent.h"
#include <QLabel>


class Freezer : public Boss {
    Q_OBJECT
    QLabel* bossWidget;

public:
    Freezer(QWidget *parent = nullptr) ;
    QWidget* widget() override {
        return bossWidget;
    }

    void specialAbility() override;
    void onDeath();


private:
    QList<Agent*> frozenAgents;
};

#endif // FREEZER_H
