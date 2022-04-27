#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QSize windowSize;
    windowSize.setHeight(::mainWindowHeight);
    windowSize.setWidth(::mainWindowWidth);
    this->setFixedSize(windowSize); // make resizable ???

    GameWidget gameWidget(0, this);
    gameWidget.setFixedSize(windowSize);
}

MainWindow::~MainWindow()
{
    delete ui;
}

