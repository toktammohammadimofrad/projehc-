#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include "Agent.h"
#include "Enemy.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void onStartButtonClicked();
    void updatePositions();

protected:
    bool eventFilter(QObject* obj, QEvent* event) override;


private:
    Ui::MainWindow *ui;
    QVector<Agent*> m_agents;
    QVector<Enemy*> m_enemies;
    QTimer* m_timer;
    QPoint m_previousPosition;

    Agent* m_selectedAgent = nullptr;

    void createAgent(int x, int y);
    void createEnemy(int x, int y);
    QLabel*welcomeLabel;};

#endif
