#include "mainwidget.h"
#include <QApplication>
#include <QMessageBox>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWidget w;




    w.show();


    return a.exec();
}
