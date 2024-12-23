#ifndef ENEMY_H
#define ENEMY_H

#include <QLabel>

class Enemy {
public:
    Enemy(int health, int damage, QLabel* label);
    void takeDamage(int amount);
    int getHealth() const;
    void move();
    QLabel* getLabel() const;

private:
    int health;
    int damage;
    QLabel* label;
};

#endif // ENEMY_H
