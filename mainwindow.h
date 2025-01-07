#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLabel>
#include <QTimer>
#include <QList>
#include "Agent.h"
#include "Enemy.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void onStartButtonClicked();
    void updatePositions();

private:
    Ui::MainWindow *ui;
    QTimer *m_timer;
    QList<Agent*> m_agents;
    QList<Enemy*> m_enemies;
    Agent *m_selectedAgent;
    QPoint m_previousPosition;

    void createAgent(int x, int y);
    void createEnemy(int x, int y);
    bool eventFilter(QObject* obj, QEvent* event) override;
};

#endif // MAINWINDOW_H
