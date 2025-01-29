#include "BoardWidget.h"
#include <QGridLayout>
#include <QLabel>

BoardWidget::BoardWidget(QWidget *parent) : QWidget(parent), m_layout(new QGridLayout(this)) {
    setLayout(m_layout);
    initializeBoard();
}

QGridLayout* BoardWidget::getBoardLayout() {
    return m_layout;
}

void BoardWidget::initializeBoard() {
    // for (int i = 0; i < 5; ++i) {
    //     for (int j = 0; j < 6; ++j) {
    //         QLabel *cellLabel = new QLabel();
    //         if (i >= 1 && i <= 4 && j >= 1 && j <= 4) {
    //             cellLabel->setStyleSheet("background-color: lightblue; border: 1px solid black;");
    //         } else if (j == 0 || j == 5) {
    //             cellLabel->setStyleSheet("background-color: lightcoral; border: 1px solid black;");
    //         } else {
    //             cellLabel->setStyleSheet("background-color: white; border: 1px solid black;");
    //         }
    //         m_layout->addWidget(cellLabel, i, j);
    //     }
    // }
}
