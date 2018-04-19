#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#include <QWidget>

namespace Ui {
class MainWidget;
}

class MainWidget : public QWidget
{
    Q_OBJECT

public:
    explicit MainWidget(QWidget *parent = 0);
    ~MainWidget();

public slots:
    void updateInfo();
    void balanceNegative();
    void wrongData();

private slots:
    void on_operationPushButton_clicked();

private:
    Ui::MainWidget *ui;
};

#endif // MAINWIDGET_H
