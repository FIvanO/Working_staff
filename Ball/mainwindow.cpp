#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QPainter>
#include <QTextStream>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    calc.setCenter(*(new QPoint(width() / 2, height() / 2)));
    file.setFileName("Input.txt");
    if (file.exists()) {
        file.open(QIODevice::ReadOnly);
        QString readY = file.readAll();
        QStringList qsl = readY.split(' ');
        calc.setCenter(*(new QPoint(calc.center().rx(), qsl[0].toInt())));
        calc.setBounce(qsl[1].toInt());
    }
    connect(&thread_1, &QThread::started, &ball, &BallObj::run);
    connect(&thread_2, &QThread::started, &calc, &Calculate::run);
//    connect(&calc, &Calculate::starting, &thread_2, &QThread::started);
//    connect(&ball, &BallObj::starting, &thread_1, &QThread::start);
    connect(&calc, &Calculate::finished, &thread_2, &QThread::quit);
    connect(&ball, &BallObj::finished, &thread_1, &QThread::quit);
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
    setBallCenter();
    QPainter painter(this);
    painter.setPen(QPen(Qt::green));
    painter.setBrush(QBrush(Qt::green));
    painter.drawEllipse(ball.center(), calc.getRad(), calc.getRad());
}

void MainWindow::on_Start_clicked()
{
//    ball.start();
//    calc.start();
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
    file.setFileName("Input.txt");
    file.open(QIODevice::WriteOnly);
    QTextStream qts(&file);
    qts << ball.CenterY() << " " << calc.getBounce();
}

void MainWindow::on_SpeedUp_clicked()
{
    int bounce_local = calc.getBounce();
    int sign = bounce_local / abs(bounce_local);
    if (abs(bounce_local) == 1) {
        calc.setBounce(bounce_local * 10);
    }
    else {
        int nB = bounce_local + (10 * sign);
        if (abs(nB) <= (height() - 3 * calc.getRad()))
        calc.setBounce(nB);
    }
}

void MainWindow::on_SpeedDown_clicked()
{
    int bounce_local = calc.getBounce();
    int sign = bounce_local / abs(bounce_local);
    if (abs(bounce_local) != 1) {
        calc.setBounce(bounce_local - (10 * sign));
    }
    if (calc.getBounce() == 0) calc.setBounce(sign);
}
