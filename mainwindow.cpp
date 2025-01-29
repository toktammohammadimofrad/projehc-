#include "MainWindow.h"
#include "StrikerFirst.h"
#include "ui_MainWindow.h"
#include "StrikerEnd.h"
#include "StrikerRandom.h"
#include "StrikerMaxHealth.h"
#include "Bomb.h"
#include "Trap.h"
#include "Soldier.h"
#include "Freezer.h"
#include "Eraser.h"
#include "Disarmer.h"
#include "Blocker.h"
#include "agent.h"
#include "Runner.h"
#include "Shielder.h"
#include "Wave.h"
#include <QMouseEvent>
#include <QDir>
#include <QVBoxLayout>
#include <QToolBar>
#include <QAction>
#include <QStatusBar>
#include <QPushButton>
#include <QRandomGenerator>
#include <QDebug>
#include <QPropertyAnimation>
#include <QMimeData>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow), m_timer(new QTimer(this)),  m_currentWave(new Wave(this)), m_elixir(0), m_selectedAgent(QString()), m_boardWidget(new BoardWidget(this)) {
    setWindowTitle("Rush Royale");

    m_boardLayout = new QGridLayout(this);
    connect(m_currentWave, &Wave::waveComplete, this, &MainWindow::onWaveComplete);
    m_currentWave->startWave(1, m_boardLayout);

    QVBoxLayout *mainLayout = new QVBoxLayout();
    QWidget *mainWidget = new QWidget(this);
    mainWidget->setLayout(mainLayout);
    setCentralWidget(mainWidget);

    m_stackedWidget = new QStackedWidget(this);
    mainLayout->addWidget(m_stackedWidget);

    createIntroPage(m_stackedWidget);

    m_stackedWidget->addWidget(m_boardWidget);

    connect(m_timer, &QTimer::timeout, this, &MainWindow::updatePositions);
}

MainWindow::~MainWindow() {
    delete m_timer;
    qDeleteAll(m_agents);
    qDeleteAll(m_enemies);
    delete m_currentWave;
    delete m_boardWidget;
}


void MainWindow::createIntroPage(QStackedWidget *stackedWidget) {
    QWidget *introPage = new QWidget(this);
    QVBoxLayout *introLayout = new QVBoxLayout(introPage);

    QLabel *introLabel = new QLabel(this);
    QString imagePath = QDir::homePath() + "/Desktop/toktam.jpg";
    QPixmap pixmap(imagePath);
    introLabel->setPixmap(pixmap.scaled(400, 300, Qt::KeepAspectRatio));

    QPushButton *startButton = new QPushButton("Start Game", this);

    introLayout->addWidget(introLabel);
    introLayout->addWidget(startButton);
    introLayout->setAlignment(Qt::AlignCenter);
    stackedWidget->addWidget(introPage);

    connect(startButton, &QPushButton::clicked, this, &MainWindow::onStartButtonClicked);
}

void MainWindow::onStartButtonClicked() {
    qDebug() << "شروع بازی";
    initializeGame();
    qDebug() << "بازی شروع شد";
    m_stackedWidget->setCurrentIndex(1);
    m_timer->start(1000);
    QTimer *enemySpawnTimer = new QTimer(this);
    connect(enemySpawnTimer, &QTimer::timeout, this, &MainWindow::spawnEnemy);
    enemySpawnTimer->start(2000);
}

void MainWindow::initializeGame() {
    createToolBars();
    createElixirLabel();


    setupWave();
    m_currentWave->startWave(1, m_boardLayout);

    lightCoralCells = {
        QPoint(0, 0), QPoint(1, 0), QPoint(2, 0),
        QPoint(3, 0), QPoint(4, 0), QPoint(0, 1),
        QPoint(0, 2), QPoint(0, 3), QPoint(0, 4),
        QPoint(0, 5), QPoint(1, 5), QPoint(2, 5),
        QPoint(3, 5), QPoint(4, 5)
    };


    QGridLayout *boardLayout = m_boardWidget->findChild<QGridLayout*>();
    if (!boardLayout) {
        qDebug() << "خطا: boardLayout پیدا نشد.";
        return;
    }

    for (int i = 0; i < 6; ++i) {
        for (int j = 0; j < 5; ++j) {
            QLabel *cellLabel = new QLabel();
            if (i >= 1 && i <= 4 && j >= 1 && j <= 4) {
                cellLabel->setStyleSheet("background-color: lightblue; border: 1px solid black;");
            }  else if ((i == 0 && j == 0) || (i == 1 && j == 0) || (i == 2 && j == 0) ||
                       (i == 3 && j == 0) || (i == 4 && j == 0) || (i == 0 && j == 1) ||
                       (i == 0 && j == 2) || (i == 0 && j == 3) || (i == 0 && j == 4) ||
                       (i == 0 && j == 5) || (i == 1 && j == 5) || (i == 2 && j == 5) ||
                       (i == 3 && j == 5) || (i == 4 && j == 5)) {
                cellLabel->setStyleSheet("background-color: lightcoral; border: 1px solid black;");
            } else {
                cellLabel->setStyleSheet("background-color: white; border: 1px solid black;");
            }
            boardLayout->addWidget(cellLabel, i, j);
            qDebug() << "افزودن ویجت به boardLayout در موقعیت: " << i << ", " << j;
        }
    }


}

void MainWindow::createToolBars() {
    QToolBar *mainToolBar = addToolBar("Main Toolbar");
    QAction *exitAction = mainToolBar->addAction("Exit");
    connect(exitAction, &QAction::triggered, this, &QMainWindow::close);


    QAction *strikerFirstAction = mainToolBar->addAction("StrikerFirst (Level 1)");
    QAction *strikerEndAction = mainToolBar->addAction("StrikerEnd (Level 1)");
    QAction *strikerRandomAction = mainToolBar->addAction("StrikerRandom (Level 1)");
    QAction *strikerMaxHealthAction = mainToolBar->addAction("StrikerMaxHealth (Level 1)");
    QAction *bombAction = mainToolBar->addAction("Bomb (Level 1)");
    QAction *trapAction = mainToolBar->addAction("Trap (Level 1)");

    connect(strikerFirstAction, &QAction::triggered, this, [=]() {
        increaseAgentLevel("StrikerFirst", strikerFirstAction);
    });
    connect(strikerEndAction, &QAction::triggered, this, [=]() {
        increaseAgentLevel("StrikerEnd", strikerEndAction);
    });
    connect(strikerRandomAction, &QAction::triggered, this, [=]() {
        increaseAgentLevel("StrikerRandom", strikerRandomAction);
    });
    connect(strikerMaxHealthAction, &QAction::triggered, this, [=]() {
        increaseAgentLevel("StrikerMaxHealth", strikerMaxHealthAction);
    });
    connect(bombAction, &QAction::triggered, this, [=]() {
        Bomb* bomb = new Bomb(this);
        bomb->explode();
    });
    connect(trapAction, &QAction::triggered, this, [=]() {
        Trap* trap = new Trap(this);
        trap->activateTrap();
    });
}

void MainWindow::createElixirLabel() {
    QLabel *elixirLabel = new QLabel("Elixir: 0", this);
    elixirLabel->setObjectName("elixirLabel");
    statusBar()->addPermanentWidget(elixirLabel);
    m_elixir = 0;

    QTimer *elixirTimer = new QTimer(this);
    connect(elixirTimer, &QTimer::timeout, this, [=]() {
        if (m_elixir < 10) {
            m_elixir += 2;
            updateElixirLabel();
        }
    });
    elixirTimer->start(1000);
}

void MainWindow::updateElixirLabel() {
    QLabel *elixirLabel = statusBar()->findChild<QLabel*>("elixirLabel");
    if (elixirLabel) {
        elixirLabel->setText("Elixir: " + QString::number(m_elixir));
    }
}



void MainWindow::setupWave() {
    m_currentWave = new Wave(this);
    connect(m_currentWave, &Wave::waveComplete, this, &MainWindow::onWaveComplete);
}

void MainWindow::onWaveComplete() {
    qDebug() << "موج تمام شد";
    QTimer::singleShot(3000, this, &MainWindow::startNextWave);
}

void MainWindow::startNextWave() {
    int nextWaveNumber = m_currentWave->waveNumber() + 1;
    m_currentWave->startWave(nextWaveNumber, m_boardLayout);
}

void MainWindow::spawnEnemy() {
    QStringList enemyTypes = {"Soldier", "Freezer", "Eraser", "Disarmer", "Runner", "Shielder"};
    QString enemyType = enemyTypes.at(QRandomGenerator::global()->bounded(enemyTypes.size()));
    createEnemy(enemyType, 0, 0);
}


void MainWindow::createAgent(const QString &agentType, int x, int y, const QString &shape) {
    Agent *agent = nullptr;

    if (agentType == "StrikerFirst") {
        agent = new StrikerFirst(this);
    } else if (agentType == "StrikerEnd") {
        agent = new StrikerEnd(this);
    } else if (agentType == "StrikerRandom") {
        agent = new StrikerRandom(this);
    } else if (agentType == "StrikerMaxHealth") {
        agent = new StrikerMaxHealth(this);
    } else if (agentType == "Bomb") {
        agent = new Bomb(this);
    } else if (agentType == "Trap") {
        agent = new Trap(this);
    }

    int cost = agent->m_elixirCost;

    if (m_elixir >= cost) {
        m_elixir -= cost;
        updateElixirLabel();
    }

    if (agent) {
        agent->setShape(shape);

        QGridLayout *boardLayout = m_boardWidget->findChild<QGridLayout*>();
        if (boardLayout) {
            boardLayout->addWidget(agent, x, y);
            m_agents.append(agent);
            m_boardWidget->update();
        } else {
            qDebug() << "خطا: boardLayout پیدا نشد.";
        }
    }
}





void MainWindow::createEnemy(const QString &enemyType, int x, int y) {
    Enemy *enemy = nullptr;

    if (enemyType == "Freezer") {
        enemy = new Freezer(this);
    } else if (enemyType == "Eraser") {
        enemy = new Eraser(this);
    } else if (enemyType == "Disarmer") {
        enemy = new Disarmer(this);
    } else if (enemyType == "Runner") {
        enemy = new Runner(this);
    } else if (enemyType == "Shielder") {
        enemy = new Shielder(this);
    }

    if (enemy) {
        QGridLayout *boardLayout = m_boardWidget->findChild<QGridLayout*>();
        if (boardLayout) {
            boardLayout->addWidget(enemy, x, y);
            m_enemies.append(enemy);
        } else {
            qDebug() << "خطا: boardLayout پیدا نشد.";
        }
    }
}


void MainWindow::increaseAgentLevel(const QString &agentType, QAction *action) {
    if (m_elixir < 2) {
        qDebug() << "مقدار اکسیر کافی نیست";
        return;
    }

    m_elixir -= 2;
    updateElixirLabel();

    for (Agent* agent : m_agents) {
        if (agent->getType() == agentType) {
            agent->increaseLevel();
        }
    }


    QString levelText = action->text();
    int levelStart = levelText.indexOf("Level") + 6;
    int currentLevel = levelText.mid(levelStart).toInt();
    action->setText(agentType + " (Level " + QString::number(currentLevel + 1) + ")");
}




void MainWindow::createRandomAgent() {

    QStringList agentTypes = {"StrikerFirst", "StrikerEnd", "StrikerRandom", "StrikerMaxHealth"};
    QString randomAgentType = agentTypes.at(QRandomGenerator::global()->bounded(agentTypes.size()));

    static bool isFirstAgent = true;
    QString randomShape;

    if (isFirstAgent) {
        randomShape = "circle";
        isFirstAgent = false;
    } else {
        static QString lastShape = "circle";
        QStringList shapes = {"triangle", "square", "pentagon", "hexagon"};

        if (lastShape == "circle") {
            randomShape = "triangle";
        } else if (lastShape == "triangle") {
            randomShape = "square";
        } else if (lastShape == "square") {
            randomShape = "pentagon";
        } else if (lastShape == "pentagon") {
            randomShape = "hexagon";
        } else {
            randomShape = shapes.at(QRandomGenerator::global()->bounded(shapes.size()));
        }

        lastShape = randomShape;
    }

    int x, y;
    bool positionFound = false;
    while (!positionFound) {
        x = QRandomGenerator::global()->bounded(1, 5);
        y = QRandomGenerator::global()->bounded(1, 5);
        if (!findAgentAtPosition(x, y)) {
            positionFound = true;
        }
    }

    createAgent(randomAgentType, x, y, randomShape);
}





void MainWindow::updatePositions() {
    for (Enemy* enemy : m_enemies) {
        QPoint currentPos = enemy->pos();
        QPoint targetPos = findLightCoralTarget(currentPos);


        if (targetPos != currentPos) {
            enemy->move(targetPos.x(), targetPos.y());
        }
        enemy->update();
    }

}


QPoint MainWindow::findLightCoralTarget(const QPoint &currentPos) {

    QPoint target = currentPos;

    for (const QPoint &lightCoral : lightCoralCells) {
        if (std::abs(currentPos.x() - lightCoral.x()) + std::abs(currentPos.y() - lightCoral.y()) <
            std::abs(currentPos.x() - target.x()) + std::abs(currentPos.y() - target.y())) {
            target = lightCoral;
        }
    }

    return target;
}


bool MainWindow::eventFilter(QObject *obj, QEvent *event) {
    if (event->type() == QEvent::MouseButtonPress) {
        QMouseEvent *mouseEvent = static_cast<QMouseEvent*>(event);
        QPoint pos = mouseEvent->pos();
        int x = pos.x() / 40;
        int y = pos.y() / 40;
        if (!m_selectedAgent.isEmpty()) {
            Agent *agent = findAgentAtPosition(x, y);
            if (agent) {
                Agent *selectedAgent = nullptr;
                for (Agent* a : m_agents) {
                    if (a->getType() == m_selectedAgent) {
                        selectedAgent = a;
                        break;
                    }
                }
                if (selectedAgent) {
                    mergeAgents(selectedAgent, agent);
                }
            } else {
                createAgent(m_selectedAgent, x, y, "circle");
            }
            m_selectedAgent.clear();
        } else {
            Agent *agent = findAgentAtPosition(x, y);
            if (agent) {
                agent->increaseLevel();
            }
        }
        return true;
    }
    return QMainWindow::eventFilter(obj, event);
}


void MainWindow::mergeAgents(Agent* agent1, Agent* agent2) {
    QString newShape;
    int num = 1;

    if (agent1->shape() == "circle" && agent2->shape() == "circle") {
        newShape = "triangle";
        num = 2;
    } else if (agent1->shape() == "triangle" && agent2->shape() == "triangle") {
        newShape = "square";
        num = 4;
    } else if (agent1->shape() == "square" && agent2->shape() == "square") {
        newShape = "pentagon";
        num = 8;
    } else if (agent1->shape() == "pentagon" && agent2->shape() == "pentagon") {
        newShape = "hexagon";
        num = 16;
    } else {
        newShape = agent1->shape();
    }

    int x = agent1->x() / 40;
    int y = agent1->y() / 40;

    m_agents.removeOne(agent1);
    m_agents.removeOne(agent2);

    delete agent1;
    delete agent2;

    Agent *mergedAgent = new StrikerRandom(this);
    mergedAgent->setShape(newShape);
    m_agents.append(mergedAgent);

    QGridLayout *boardLayout = m_boardWidget->findChild<QGridLayout*>();
    if (boardLayout) {
        boardLayout->addWidget(mergedAgent, x, y);
    }

    // افزایش سرعت شلیک در نتیجه ادغام
    QTimer *mergedShootTimer = new QTimer(this);
    connect(mergedShootTimer, &QTimer::timeout, mergedAgent, [=]() {
        if (!mergedAgent->isFrozen()) {
            Enemy* target = findFirstEnemy();
            if (target) {
                mergedAgent->shoot(target->pos());
                target->takeDamage(15 * mergedAgent->level());
            }
        }
    });
    mergedShootTimer->start(1000 / num);
}


Agent* MainWindow::findAgentAtPosition(int x, int y) {
    for (Agent* agent : m_agents) {
        if (agent->x() / 40 == x && agent->y() / 40 == y) {
            return agent;
        }
    }
    return nullptr;
}


Enemy* MainWindow::findFirstEnemy() {
    Enemy* closestEnemy = nullptr;
    double minDistance = std::numeric_limits<double>::infinity();

    for (Enemy* enemy :  m_enemies) {

        double enemyX = enemy->x();
        double enemyY = enemy->y();
        double distance = std::sqrt(std::pow(enemyX - this->x(), 2) + std::pow(enemyY - this->y(), 2));



        if (distance < minDistance) {
            minDistance = distance;
            closestEnemy = enemy;
        }
    }

    return closestEnemy;
}


QList<Agent*> MainWindow::getAgents() const {
    return m_agents;
}

void MainWindow::removeAgent(Agent *agent) {
    m_agents.removeOne(agent);
    delete agent;
}



