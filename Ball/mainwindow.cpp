#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QPainter>
#include <QTextStream>
#include <QCloseEvent>
#include <QSignalSpy>

MainWindow::MainWindow(QWidget *parent) :
QMainWindow(parent),
ui(new Ui::MainWindow)
{
	ui->setupUi(this);
	myDb.setConnection();
	myGlobalDb.setGlobalConnection();
	int curr_Y = myGlobalDb.getY();
	int curr_Bounce = myGlobalDb.getBounce();
	myDb.setY(curr_Y);
	myDb.setBounce(curr_Bounce);
	m_spy = new QSignalSpy(&calc, SIGNAL(sendCoor(int)));
	calc.setCenter(*(new QPoint(width() / 2, height() / 2)));
	calc.setCenter(QPoint(calc.center().rx(), myDb.getY()));
	calc.setBounce(myDb.getBounce());
	connect(&calc, &Calculate::finished, &thread_2, &QThread::quit, Qt::DirectConnection);
	connect(&ball, &BallObj::finished, &thread_1, &QThread::quit, Qt::DirectConnection);
	connect(&calc, &Calculate::sendCoor, &ball, &BallObj::setCenterY, Qt::DirectConnection);
	connect(&timer, &QTimer::timeout, this, &MainWindow::rePaint);
	connect(&calc, &Calculate::condChanged, &calc, &Calculate::processing);
	connect(&ball, &BallObj::condChanged, &ball, &BallObj::processing);
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
	ball.setCond(true);
	calc.setcond(true);
	thread_1.start();
	thread_2.start();
	timer.start();
}

void MainWindow::rePaint()
{
	if (!calc.cond()) return ;
	if (!ball.cond()) return ;
	calc.processing();
	ball.processing();
	myDb.setY(ball.CenterY());
	myDb.setBounce(calc.getBounce());
	repaint();
}

void MainWindow::on_Stop_clicked()
{
	int curr_Y = myDb.getY();
	int curr_Bounce = myDb.getBounce();
	myGlobalDb.setY(curr_Y);
	myGlobalDb.setBounce(curr_Bounce);
	ball.setCond(false);
	calc.setcond(false);
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

void MainWindow::check()
{
	qDebug() << "Thread finished";
}

void MainWindow::closeEvent (QCloseEvent *event) {
	on_Stop_clicked();
	thread_1.wait();
	thread_2.wait();
	event->accept();
}
