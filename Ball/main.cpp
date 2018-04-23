#include "mainwindow.h"
#include <QApplication>
#include <QtSql>
#include <QDebug>
#include <QSqlQuery>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;

//    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
//    db.setDatabaseName("myDb.sqlite");
//    QSqlQuery sq("CREATE TABLE COORD ( "
//                 "  ID INT PRIMARY KEY"
//	"  NAME TEXT)");

//    db.exec(sq);

//    if (!db.isOpen()) {
//        qDebug() << "Db isn't open!";
//        db.open();
//        db.setUserName("FIvanO");
//        db.setPassword("qsewad123");
//        db.close();
//    }

//    QSqlQuery sq
//    if (!db)

    w.show();

    return a.exec();
}
