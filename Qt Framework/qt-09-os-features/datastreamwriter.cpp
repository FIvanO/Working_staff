#include "datastreamwriter.h"

#include <QFile>
#include <QDataStream>
#include <QDebug>

DataStreamWriter::DataStreamWriter(QString fileName, QObject *parent) : QObject(parent)
{
    // TODO: open file and create QDataStream
}

DataStreamWriter::~DataStreamWriter()
{
    // TODO: delete stream and file
}

void DataStreamWriter::writeData(double data)
{
    // TODO: write data to the stream
}
