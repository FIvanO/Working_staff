#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QPainter>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    file.setFileName("Input.txt");
    if (file.exists()) {
        file.open(QIODevice::ReadOnly);
        QString readY = file.readAll();

    }
    connect(&thread_1, &QThread::started, &ball, &BallObj::run);
    connect(&thread_2, &QThread::started, &calc, &Calculate::run);
    //connect(&calc, &Calculate::finished, &thread_1, &QThread::quit);
    connect(&calc, &Calculate::sendCoor, &ball, &BallObj::setCenterY, Qt::DirectConnection);
    connect(&timer, &QTimer::timeout, this, &MainWindow::rp);
    calc.moveToThread(&thread_1);
    ball.moveToThread(&thread_2);
    timer.setInterval(50);
}

void MainWindow::setBallCenter()
{
   ball.setCenter(calc.center());
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);
    QPainter painter(this);
    painter.setPen(QPen(Qt::green));
    painter.setBrush(QBrush(Qt::green));
    painter.drawEllipse(ball.center(), calc.getRad(), calc.getRad());
    setBallCenter();
}

void MainWindow::on_Start_clicked()
{
    ball.setCond(true);
    calc.setcond(true);
    thread_1.start();
    thread_2.start();
    timer.start();
}

void MainWindow::rp()
{
    repaint();
}

void MainWindow::on_Stop_clicked()
{
    ball.setCond(false);
    calc.setcond(false);
}
