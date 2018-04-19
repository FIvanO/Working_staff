#include "textstreamreader.h"

#include <QDebug>
#include <QFile>
#include <QTextStream>

TextStreamReader::TextStreamReader(QObject *parent) : QObject(parent)
{

}

void TextStreamReader::readFromFile(QString fileName)
{
    // TODO: open file in readonly mode

    // TODO: create QTextStream
    forever {
        // TODO: read from stream and emit required signal on each row
        break;
    }
    emit allDataReaded();
    qDebug() << "End of input file";
}
