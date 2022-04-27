#ifndef GAMEWIDGET_H
#define GAMEWIDGET_H

#include <QWidget>
#include <QPalette>
#include <QColor>
#include <QList>
#include <QGridLayout>
#include <QRect>
#include <QDebug>

#include <iostream>

#include "constants.h"
#include "gamebutton.h"

class GameWidget : public QWidget
{
    Q_OBJECT
public:
    explicit GameWidget(int gameSize, QWidget *parent = nullptr);

signals:

public slots:
    void toggleButton(int row, int col); // make python binding
    void handleGameButtonClicked(int row, int col);

private:
    void createButtons();
    void deleteButtons();
    void positionButtons();

    int m_gameSize;
    QList<QList <GameButton *> > m_buttons;
    QGridLayout m_buttonLayout;

};

#endif // GAMEWIDGET_H
