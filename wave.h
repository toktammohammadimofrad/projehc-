#ifndef WAVE_H
#define WAVE_H

#include <QObject>
#include <QGridLayout>
#include <QList>
#include <QTimer>
#include <QRandomGenerator>
#include "enemy.h"
#include "soldier.h"
#include "boss.h"

class Wave : public QObject {
    Q_OBJECT

public:
    explicit Wave(QObject *parent = nullptr);
    ~Wave();

    void startWave(int waveNumber, QGridLayout *boardLayout);
    void spawnEnemy();
    void increaseEnemyStats();
    bool isWaveComplete() const;
    int waveNumber() const { return m_waveNumber; }

signals:
    void waveComplete();

private:
    QList<Enemy*> m_enemies;
    int m_waveNumber;
    int m_enemiesSpawned;
    QTimer *m_waveTimer;
    QTimer *m_enemySpawnTimer;
    bool m_isBossWave;
    void spawnBoss();
    QGridLayout* boardLayout;
};

#endif
