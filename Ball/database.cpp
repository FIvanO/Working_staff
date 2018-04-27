#include "database.h"
#include <QStringBuilder>
#include <QFile>
#include <QDir>
#include <QSqlQuery>
#include <QMap>
#include <QDebug>
#include <QSqlError>

DataBase::DataBase(QObject *parent) : QObject(parent)
{

}

void DataBase::newConnection()
{
	db = QSqlDatabase::addDatabase("QSQLITE", "localDb");
	db.setDatabaseName("dataBase.db");
	db.open();
}

void DataBase::newGlobalConnection()
{
	db = QSqlDatabase::addDatabase("QSQLITE", "globalDb");
	db.setDatabaseName("GlobalDataBase.db");
	db.setHostName("Global");
	db.setPort(2020);
	db.setUserName("FIvanO");
	db.open();
}

void DataBase::init()
{
	QMap<QString, QString> myMap;
	myMap["y"] = "integer";
	createTable("ball_y", "integer", myMap);
	myMap.clear();
	myMap["bounce"] = "integer";
	createTable("ball_bounce", "integer", myMap);
}

bool DataBase::isExist()
{
	return QFile(QDir::currentPath() + "dataBase.db").exists();

}

void DataBase::setConnection()
{
	if (!isExist()) {
		newConnection();
		init();
	} else {
		db.open();
	}
}

void DataBase::setGlobalConnection()
{
	if (!db.open()) {
		newGlobalConnection();
		init();
	} else {
		db.open();
	}
}

void DataBase::createTable(QString tableName, QString primaryKeyType, QMap<QString, QString> &columnNameType)
{
	QString newTable = "CREATE TABLE IF NOT EXISTS " % tableName % " (id " % primaryKeyType + " PRIMARY KEY ";
	for (auto it = columnNameType.begin(); it != columnNameType.end(); ++it) {
		newTable += ", " % it.key() % " " % it.value();
	}
	newTable += ");";
	QSqlQuery query(newTable, db);
	QSqlQuery ins(db);
	ins.prepare("INSERT INTO " % tableName % "(id, " % columnNameType.begin().key() % " ) VALUES(0, 10);");
	ins.exec();
}

int DataBase::getY()
{
	QSqlQuery query("SELECT y FROM ball_y;", db);
	if (query.next()) {
		return query.value(0).toInt();
	}
}

void DataBase::setY(int _y)
{
	QSqlQuery upd(db);
	upd.prepare("UPDATE ball_y set y = :y WHERE id = 0;");
	upd.bindValue(":y", _y);
	upd.exec();
}

void DataBase::setBounce(int _bounce)
{
	QSqlQuery upd(db);
	upd.prepare("UPDATE ball_bounce set bounce = :bounce WHERE id = 0;");
	upd.bindValue(":bounce", _bounce);
	upd.exec();
}

int DataBase::getBounce()
{
	QSqlQuery query("SELECT bounce FROM ball_bounce;", db);
	if (query.next()) {
		return query.value(0).toInt();
	}
}
