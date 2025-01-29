#include "freezer.h"
#include "MainWindow.h"
#include <QList>
#include <cstdlib>
#include <QWidget>

Freezer::Freezer(QWidget *parent) : Boss(parent) {
    bossWidget = new QLabel("Freezer");
    setLabel("Freezer");
    abilityTimer->start(5000);
}

void Freezer::specialAbility() {
    MainWindow *mainWindow = qobject_cast<MainWindow*>(parent());
    if (!mainWindow) return;
    QList<Agent*> agents = mainWindow->getAgents();
    if (agents.isEmpty()) return;


    int randomIndex = rand() % agents.size();
    Agent* agentToFreeze = agents[randomIndex];
    agentToFreeze->setFrozen(true);
    frozenAgents.append(agentToFreeze);
}


void Freezer::onDeath() {
    for (Agent* agent : frozenAgents) {
        agent->setFrozen(false);
    }
}

