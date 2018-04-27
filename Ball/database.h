#ifndef DATABASE_H
#define DATABASE_H

#include <QObject>
#include <QSqlDatabase>
#include <QString>
#include <QStringList>
#include <QMap>

class DataBase : public QObject
{
    Q_OBJECT
public:
	explicit DataBase(QObject *parent = nullptr);
	void setConnection();
	void setGlobalConnection();
	int getY();
	void setY(int _y);
	void setBounce(int _bounce);
	int getBounce();
	void createTable(QString tableName, QString primaryKeyType,	QMap<QString, QString> &columnNameType);

signals:

public slots:

private:
	QSqlDatabase db;
	void newConnection();
	void newGlobalConnection();
	void init();
	bool isExist();
};



#endif // DATABASE_H
