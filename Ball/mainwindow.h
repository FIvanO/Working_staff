#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QThread>
#include "ballobj.h"
#include "calculate.h"
#include <QTimer>
#include <QFile>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    void setBallCenter();
    ~MainWindow();

protected:
    void paintEvent(QPaintEvent *event);

private slots:
    void on_Start_clicked();
    void rp();

    void on_pushButton_clicked();

    void on_Stop_clicked();

private:
    Ui::MainWindow *ui;
    QThread thread_1;
    QThread thread_2;
    BallObj ball;
    Calculate calc;
    QTimer timer;
    QFile file;
};

#endif // MAINWINDOW_H
