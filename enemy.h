#ifndef ENEMY_H
#define ENEMY_H

#include "BaseAgent.h"

class Enemy : public BaseAgent {
    Q_OBJECT

public:
    explicit Enemy(QLabel* label, QObject* parent = nullptr);
    void move() override;

    enum Type { Soldier, BossEraser, BossFreezer, BossDisarmer };
    void setType(Type type);
    Type getType() const;

private:
    Type m_type;
    float m_speed;
};

#endif // ENEMY_H
