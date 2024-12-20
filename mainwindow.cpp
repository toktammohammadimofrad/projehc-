#include "MainWindow.h"
#include "ui_MainWindow.h"
#include "Logger.h"
#include <QMouseEvent>
#include <QDir>
#include <QRandomGenerator>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , m_timer(new QTimer(this))
{
    ui->setupUi(this);

    QString imagePath = QDir::homePath() + "/Desktop/tiam.jpg";
    QPixmap pixmap(imagePath);
    ui->introLabel->setPixmap(pixmap.scaled(ui->introLabel->size(), Qt::KeepAspectRatio));

    connect(ui->startButton, &QPushButton::clicked, this, &MainWindow::onStartButtonClicked);

    ui->stackedWidget->setCurrentWidget(ui->introLabel);

    connect(m_timer, &QTimer::timeout, this, &MainWindow::updatePositions);


    ui->board->installEventFilter(this);
}

MainWindow::~MainWindow()
{
    delete ui;
    delete m_timer;
    qDeleteAll(m_agents);
    qDeleteAll(m_enemies);
}

void MainWindow::onStartButtonClicked()
{
    ui->stackedWidget->setCurrentWidget(ui->board);

    QGridLayout *boardLayout = new QGridLayout(ui->board);
    ui->board->setLayout(boardLayout);

    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 6; ++j) {
            QLabel *cellLabel = new QLabel();
            if (i >= 1 && i <= 4 && j >= 1 && j <= 4) {

                cellLabel->setStyleSheet("background-color: lightblue; border: 1px solid black;");
            } else if ((i == 0 && j == 0) || (i == 1 && j == 0) || (i == 2 && j == 0) ||
                       (i == 3 && j == 0) || (i == 4 && j == 0) || (i == 0 && j == 1) ||
                       (i == 0 && j == 2) || (i == 0 && j == 3) || (i == 0 && j == 4) ||
                       (i == 0 && j == 5) || (i == 1 && j == 5) || (i == 2 && j == 5) ||
                       (i == 3 && j == 5) || (i == 4 && j == 5)) {

                cellLabel->setStyleSheet("background-color: lightcoral; border: 1px solid black;");
            } else {
                cellLabel->setStyleSheet("background-color: white; border: 1px solid black;");
            }
            boardLayout->addWidget(cellLabel, i, j);
        }
    }


    createAgent(5, 1);
    createAgent(5, 2);
    createAgent(5, 3);
    createAgent(5, 4);
    createEnemy(4, 0);

    m_timer->start(1000);

    Logger::instance().writeLog("Game started.");
}

void MainWindow::createAgent(int x, int y) {
    QLabel* agentLabel = new QLabel("Agent");
    agentLabel->setStyleSheet("background-color: blue; border: 1px solid black;");
    agentLabel->installEventFilter(this);
    dynamic_cast<QGridLayout*>(ui->board->layout())->addWidget(agentLabel, x, y);
    Agent* agent = new Agent(agentLabel);
    m_agents.append(agent);
}

void MainWindow::createEnemy(int x, int y) {
    QLabel* enemyLabel = new QLabel("Enemy");
    enemyLabel->setStyleSheet("background-color: red; border: 1px solid black;");
    dynamic_cast<QGridLayout*>(ui->board->layout())->addWidget(enemyLabel, x, y);
    Enemy* enemy = new Enemy(enemyLabel);
    m_enemies.append(enemy);
}

bool MainWindow::eventFilter(QObject* obj, QEvent* event) {
    if (obj == ui->board && event->type() == QEvent::MouseButtonPress) {

        if (m_selectedAgent) {

            QMouseEvent* mouseEvent = static_cast<QMouseEvent*>(event);
            QPoint boardPos = ui->board->mapFromGlobal(mouseEvent->globalPos());


            QGridLayout* layout = dynamic_cast<QGridLayout*>(ui->board->layout());
            int row = boardPos.y() / (ui->board->height() / layout->rowCount());
            int col = boardPos.x() / (ui->board->width() / layout->columnCount());

            layout->addWidget(m_selectedAgent->getLabel(), row, col);

            if (!m_agents.isEmpty()) {

                int randomIndex = QRandomGenerator::global()->bounded(m_agents.size());
                Agent* randomAgent = m_agents[randomIndex];


                QLabel* newAgentLabel = new QLabel("Agent");
                newAgentLabel->setStyleSheet(randomAgent->getLabel()->styleSheet());
                dynamic_cast<QGridLayout*>(ui->board->layout())->addWidget(newAgentLabel, m_previousPosition.x(), m_previousPosition.y());

                Agent* newAgent = new Agent(newAgentLabel);
                m_agents.append(newAgent);
            }

            if (m_agents.size() > 8) {
                Agent* toRemove = m_agents.takeFirst();
                delete toRemove->getLabel();
                delete toRemove;
            }

            m_selectedAgent = nullptr;
        }
        return true;
    }


    for (Agent* agent : m_agents) {
        if (agent->getLabel() == obj && event->type() == QEvent::MouseButtonPress) {
            m_selectedAgent = agent;


            QGridLayout* layout = dynamic_cast<QGridLayout*>(ui->board->layout());
            int index = layout->indexOf(agent->getLabel());
            int row, col, rowSpan, colSpan;
            layout->getItemPosition(index, &row, &col, &rowSpan, &colSpan);

            m_previousPosition = QPoint(row, col);

            return true;
        }
    }

    return QMainWindow::eventFilter(obj, event);
}


void MainWindow::updatePositions() {
    for (Agent* agent : m_agents) {
        agent->move();
        Logger::instance().writeLog("Agent moved.");
    }

    for (Enemy* enemy : m_enemies) {
        enemy->move();
        Logger::instance().writeLog("Enemy moved.");
    }
}
