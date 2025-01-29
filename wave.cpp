#include "wave.h"
#include "soldier.h"
#include "boss.h"
#include "freezer.h"
#include "eraser.h"
#include "disarmer.h"
#include "runner.h"
#include "Shielder.h"
#include <QGridLayout>
#include <QRandomGenerator>
#include <QDebug>
#include <cstdlib>
#include <ctime>

Wave::Wave(QObject *parent) : QObject(parent), m_waveNumber(0), m_enemiesSpawned(0), m_isBossWave(false) {
    m_waveTimer = new QTimer(this);
    m_enemySpawnTimer = new QTimer(this);

    connect(m_enemySpawnTimer, &QTimer::timeout, this, &Wave::spawnEnemy);
    connect(m_waveTimer, &QTimer::timeout, this, &Wave::increaseEnemyStats);
}

Wave::~Wave() {
    qDeleteAll(m_enemies);
}

void Wave::startWave(int waveNumber, QGridLayout *boardLayout) {
    m_waveNumber = waveNumber;
    m_enemiesSpawned = 0;
    m_isBossWave = (waveNumber % 2 == 0);

    m_enemySpawnTimer->start(1000);
    m_waveTimer->start(1000);
}

void Wave::spawnEnemy() {
    if (m_enemiesSpawned < 20) {
        static bool initialized = false;
        if (!initialized) {
            std::srand(std::time(nullptr));
            initialized = true;
        }


        int randomType = std::rand() % 2;

        Enemy *enemy;
        if (randomType == 0) {
            enemy = new Runner();
        } else {
            enemy = new Shielder();
        }
        m_enemies.append(enemy);
        boardLayout->addWidget(enemy->widget(), 4, 0);

        m_enemiesSpawned++;
        if (m_isBossWave && m_enemiesSpawned == 20) {
            spawnBoss();
        }
    } else {
        m_enemySpawnTimer->stop();
        emit waveComplete();
    }
}

void Wave::spawnBoss() {

    static bool initialized = false;
    if (!initialized) {
        std::srand(std::time(nullptr));
        initialized = true;
    }


    int randomType = std::rand() % 3;

    Boss *boss;
    if (randomType == 0) {
        boss = new Freezer();
    } else if (randomType == 1) {
        boss = new Disarmer();
    } else {
        boss = new Eraser();
    }

    boardLayout->addWidget(boss->widget(), 4, 0);

    m_enemies.append(boss);
}

void Wave::increaseEnemyStats() {
    for (Enemy *enemy : m_enemies) {
        enemy->setHealth(enemy->health() * 1.1);
        enemy->setSpeed(enemy->speed() * 1.1);
    }
}

bool Wave::isWaveComplete() const {
    return m_enemiesSpawned >= 20;
}


