#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "calculate.h"
#include "ballobj.h"
#include "database.h"
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
	QPoint pt(width() / 2, height() / 2);
	calc = new Calculate(nullptr, pt);
	ball = new BallObj(nullptr, pt);
	myDb = new DataBase;
	preProcessing();
}

void MainWindow::preProcessing()
{
	connect(ball, &BallObj::finished, &thread_1, &QThread::quit, Qt::DirectConnection);
	connect(calc, &Calculate::finished, &thread_2, &QThread::quit, Qt::DirectConnection);
	connect(myDb, &DataBase::localFinished, &thread_3, &QThread::quit, Qt::DirectConnection);
	connect(calc, &Calculate::sendCoor, ball, &BallObj::setCenterY);
	connect(calc, &Calculate::bounceChanged, this, &MainWindow::localDbBounceUpd);
	connect(&timer, &QTimer::timeout, this, &MainWindow::rePaint);
	connect(calc, &Calculate::condChanged, calc, &Calculate::processing);
	connect(ball, &BallObj::condChanged, ball, &BallObj::processing);
	connect(this, &MainWindow::s_localDbBounceUpd, myDb, &DataBase::setBounce);
	connect(this, &MainWindow::s_localDbYUpd, myDb, &DataBase::setY);
	connect(this, &MainWindow::s_calculateProcessing, calc, &Calculate::processing);
	connect(this, &MainWindow::s_ballObjProcessing, ball, &BallObj::processing);
	connect(this, &MainWindow::s_setBallCenter, ball, &BallObj::setCenter, Qt::DirectConnection);
	calc->moveToThread(&thread_1);
	ball->moveToThread(&thread_2);
	myDb->moveToThread(&thread_3);
	myDb->setConnection();
	myGlobalDb.setGlobalConnection();
	int curr_Y = myGlobalDb.getY();
	int curr_Bounce = myGlobalDb.getBounce();
	myDb->setY(curr_Y);
	myDb->setBounce(curr_Bounce);
	calc->setCenter(QPoint(calc->center().rx(), curr_Y));
	calc->setBounce(curr_Bounce);
	setBallCenter();
	timer.setInterval(10);
}

void MainWindow::setBallCenter()
{
	emit s_setBallCenter(calc->center());
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
	painter.drawEllipse(ball->center(), calc->getRad(), calc->getRad());
}

void MainWindow::localDbBounceUpd()
{
	emit s_localDbBounceUpd(calc->getBounce());
}

void MainWindow::localDbYUpd()
{
	emit s_localDbYUpd(ball->CenterY());
}

void MainWindow::calculateProcessing()
{
	emit s_calculateProcessing();
}

void MainWindow::ballObjProcessing()
{
	emit s_ballObjProcessing();
}

void MainWindow::on_Start_clicked()
{
	ball->setCond(true);
	calc->setcond(true);
	thread_1.start();
	thread_2.start();
	thread_3.start();
	timer.start();
}

void MainWindow::rePaint()
{
	if (!calc->cond()) return ;
	if (!ball->cond()) return ;
	calculateProcessing();
	ballObjProcessing();
	setBallCenter();
	localDbYUpd();
	localDbBounceUpd();
	repaint();
}

void MainWindow::on_Stop_clicked()
{
	int curr_Y = myDb->getY();
	int curr_Bounce = myDb->getBounce();
	myGlobalDb.setY(curr_Y);
	myGlobalDb.setBounce(curr_Bounce);
	ball->setCond(false);
	calc->setcond(false);
	myDb->finish();
}

void MainWindow::on_SpeedUp_clicked()
{
	int bounce_local = calc->getBounce();
	int sign = bounce_local / abs(bounce_local);
	if (abs(bounce_local) == 1) {
		calc->setBounce(bounce_local * 10);
	}
	else {
		int nB = bounce_local + (10 * sign);
		if (abs(nB) <= (height() - 3 * calc->getRad()))
			calc->setBounce(nB);
	}
}

void MainWindow::on_SpeedDown_clicked()
{
	int bounce_local = calc->getBounce();
	int sign = bounce_local / abs(bounce_local);
	if (abs(bounce_local) != 1) {
		calc->setBounce(bounce_local - (10 * sign));
	}
	if (calc->getBounce() == 0) calc->setBounce(sign);
}

void MainWindow::check()
{
	qDebug() << "Thread finished";
}

void MainWindow::closeEvent (QCloseEvent *event) {
	on_Stop_clicked();
	thread_1.wait();
	thread_2.wait();
	thread_3.wait();
	event->accept();
}
