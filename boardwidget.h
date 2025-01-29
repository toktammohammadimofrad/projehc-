#ifndef BOARDWIDGET_H
#define BOARDWIDGET_H

#include <QWidget>
#include <QGridLayout>

class BoardWidget : public QWidget {
    Q_OBJECT

public:
    BoardWidget(QWidget *parent = nullptr);
    QGridLayout* getBoardLayout();

private:
    QGridLayout *m_layout;

    void initializeBoard();
};

#endif
