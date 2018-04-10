#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPainter>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(&thread_1, &QThread::started, &ball, &BallObj::run);
    //connect(&thread_2, &QThread::started, &calc, &Calculate::run);
    connect(&calc, &Calculate::finished, &thread_1, &QThread::terminate);
    calc.moveToThread(&thread_1);
    ball.setCond(true);
    calc.setcond(true);
    thread_1.start();
    thread_2.start();
}

void MainWindow::start()
{
    ball.setCond(true);
    calc.setcond(true);
    thread_1.start();
    thread_2.start();
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

    repaint();
}
