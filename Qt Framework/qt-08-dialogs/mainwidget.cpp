#include "mainwidget.h"
#include "ui_mainwidget.h"

#include <QMessageBox>
#include <QInputDialog>
#include <QFileDialog>
#include <QColorDialog>
#include <QDebug>

MainWidget::MainWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MainWidget)
{
    ui->setupUi(this);
}

MainWidget::~MainWidget()
{
    delete ui;
}

void MainWidget::on_messageBoxPushButton_clicked()
{
    // TODO: show any text with message box
    QMessageBox::information(this, "Smth", "Showing smth", QMessageBox::Ok);
}

void MainWidget::on_integerPushButton_clicked()
{
    // TODO: create dialog and get user input
    bool ok;
    int result = QInputDialog::getInt(this, "Value input", "Please input integer", 0, -2147483647, 2147483647, 1, &ok);
    // TODO: set text of integerLineEdit
    if (ok) {
        findChild<QLineEdit *>("integerLineEdit")
            ->setText(QString::number(result));
    }
}

void MainWidget::on_filePushButton_clicked()
{
    // TODO: create dialog and get user input
    QString fileName = QFileDialog::getOpenFileName(this);
    // TODO: set text of fileLineEdit
    if (fileName != "") {
        findChild<QLineEdit *>("fileLineEdit")
            ->setText(fileName);
    }
}

void MainWidget::on_colorPushButton_clicked()
{
    // TODO: create dialog and get user input
    QColor color = QColorDialog::getColor();
    // TODO: set text of colorLineEdit
    if (color.isValid()) {
        findChild<QLineEdit *>("colorLineEdit")
            ->setText(color.name());
    }
}
