#include "disarmer.h"
#include "MainWindow.h"
#include <QList>
#include <cstdlib>
#include <QWidget>

Disarmer::Disarmer(QWidget *parent) : Boss(parent) {
    bossWidget = new QLabel("Disarmer");

    setLabel("Disarmer");
    abilityTimer->start(7000);
}

void Disarmer::specialAbility() {
    MainWindow *mainWindow = qobject_cast<MainWindow*>(parent());
    if (!mainWindow) return;
    QList<Agent*> agents = mainWindow->getAgents();
    for (Agent* agent : agents) {
        if ((agent->getType() == "Bomb" || agent->getType() == "Trap") && isInRange(agent)) {
            mainWindow->removeAgent(agent);
        }
    }
}


