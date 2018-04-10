#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QThread>
#include "ballobj.h"
#include "calculate.h"
#include <QTimer>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    void start();
    void setBallCenter();
    ~MainWindow();

protected:
    void paintEvent(QPaintEvent *event);

private slots:
    void on_Start_clicked();
    void rp();

private:
    Ui::MainWindow *ui;
    QThread thread_1;
    QThread thread_2;
    BallObj ball;
    Calculate calc;
    QTimer timer;
};

#endif // MAINWINDOW_H
