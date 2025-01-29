#ifndef ERASER_H
#define ERASER_H

#include "boss.h"

class Eraser : public Boss {
    Q_OBJECT
    QLabel* bossWidget;
public:
    Eraser(QWidget *parent = nullptr);
    QWidget* widget() override {
        return bossWidget;
    }
    void specialAbility() override;
};

#endif
