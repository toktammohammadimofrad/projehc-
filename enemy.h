#ifndef ENEMY_H
#define ENEMY_H

#include <QObject>
#include <QLabel>
#include <QVector>
#include <QPoint>

class Enemy : public QObject {
    Q_OBJECT
public:
    Enemy(QLabel* label, QObject* parent = nullptr);

    void move();
    QLabel* getLabel() const;

private:
    QLabel* m_label;
    QVector<QPoint> m_path;
    int m_currentStep;
};

#endif
