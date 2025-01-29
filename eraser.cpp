#include "eraser.h"
#include "MainWindow.h"
#include <QList>
#include <cstdlib>
#include <QWidget>

Eraser::Eraser(QWidget *parent) : Boss(parent) {
    bossWidget = new QLabel("Eraser");
    setLabel("Eraser");
    abilityTimer->start(7000);
}

void Eraser::specialAbility() {
    MainWindow *mainWindow = qobject_cast<MainWindow*>(parent());
    if (!mainWindow) return;
    QList<Agent*> agents = mainWindow->getAgents();
    if (agents.isEmpty()) return;


    int randomIndex = rand() % agents.size();
    Agent* agentToRemove = agents[randomIndex];
    mainWindow->removeAgent(agentToRemove);
}

