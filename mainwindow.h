#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include <QLabel>
#include <QList>
#include <QStackedWidget>
#include <QGridLayout>
#include "agent.h"
#include "enemy.h"
#include "wave.h"
#include "boardWidget.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE


class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    Enemy* findFirstEnemy();
    QList<Agent*> getAgents() const;

    void removeAgent(Agent *agent);

    QList<Enemy*> getEnemies() const { return m_enemies; }




private:
    Ui::MainWindow *ui;
    QTimer *m_timer;
    int m_elixir;
    QString m_selectedAgent;
    BoardWidget *m_boardWidget;
    QStackedWidget *m_stackedWidget;
    QPoint m_previousPosition;
    QList<Agent*> m_agents;
    QList<Enemy*> m_enemies;
    QList<QPoint> lightCoralCells;
    QPoint findLightCoralTarget(const QPoint &currentPos);
    Wave *m_currentWave;
    QGridLayout *m_boardLayout;

    Agent* findAgentAtPosition(int x, int y);


    void createIntroPage(QStackedWidget *stackedWidget);
    void initializeGame();
    void createToolBars();
    void createElixirLabel();

    void createAgent(const QString &agentType, int x, int y, const QString &shape);
    void createEnemy(const QString &enemyType, int x, int y);
    void increaseAgentLevel(const QString &agentType, QAction *action);
    void mergeAgents(Agent *agent1, Agent *agent2);

    void createRandomAgent();
    void updateElixirLabel();
    void setupWave();
    void startNextWave() ;


private slots:
    void onStartButtonClicked();
    void spawnEnemy();
    void updatePositions();
    void onWaveComplete();

protected:
    bool eventFilter(QObject *obj, QEvent *event) override;

};

#endif
