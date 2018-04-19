#include <QCoreApplication>
#include <QDebug>
#include <QStack>
#include <QString>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QList<QString> names;
    names << "Mary" << "Ann" << "Charlynn" << "Marylynn" << "Margaret"
          << "Kate" << "Rose" << "Gwendolyn";


    qDebug() << "<<< Longest with Java-style >>>";
    QListIterator<QString> javaIterator(names);

    QString longestName;

    while(javaIterator.hasNext()) {
        QString currentName = javaIterator.next();
        if (longestName.length() < currentName.length()) {
            longestName = currentName;
        }
    }

    QString output("Longest name: %1");
    qDebug() << output.arg(longestName);


    qDebug() << "";
    qDebug() << "<<< Shortest name with STL-style >>>";
    QString shortestName;
    for (QList<QString>::iterator it = names.begin(); it != names.end(); ++it) {
        if (shortestName.isNull()) {
            shortestName = *it;
        }
        if (shortestName.length() > it->length()) {
            shortestName = *it;
        }
    }

    qDebug() << shortestName.prepend("Shortest name: ");


    qDebug() << "";
    qDebug() << "<<< With suffix \"lynn\" >>>";
    QStringList namesList;
    foreach (QString name, names) {
        if (name.contains("lynn")) {
            namesList += name;
        }
    }
    qDebug() << namesList.join(',');


    // print all names in reverse order
    // TODO: 1. Using QStack
    QStack<QString> st;
    foreach(auto name, names) {
        st.push(name);
    }
    QString out;
    while (!st.empty()) {
        out += st.pop() + " ";
    }
    qDebug() << "";
    qDebug() << out;

    // TODO: 2. Using other QList
    QList<QString> ls;
    foreach (auto name, names) {
        ls.push_front(name);
    }
    qDebug() << "";
    qDebug() << ls;

    // TODO: 3. Without other containers
    QString outW;
    while (!names.empty()) {
        outW += names.back() + " ";
        names.removeLast();
    }
    qDebug() << "";
    qDebug() << outW;

    return a.exec();
}
