#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLabel>
#include <QTimer>
#include <QGridLayout>
#include <vector>
#include "AgentBase.h"
#include "StrikerFirst.h"
#include "Enemy.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    explicit MainWindow(QWidget* parent = nullptr);
    ~MainWindow();

protected:
    bool eventFilter(QObject* watched, QEvent* event) override;

private slots:
    void onStartButtonClicked();

private:
    Ui::MainWindow* ui;
    QTimer* m_timer;
    std::vector<AgentBase*> m_agents;
    std::vector<Enemy*> m_enemies;
    AgentBase* m_selectedAgent = nullptr;
    QPoint m_previousPosition;

    void createAgent(int x, int y);
    void createEnemy(int health, int damage, int x, int y);
    void updatePositions();
};

#endif // MAINWINDOW_H
