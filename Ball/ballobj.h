#ifndef BALLOBJ_H
#define BALLOBJ_H

#include <QObject>
#include <QPoint>

class BallObj : public QObject
{
    Q_OBJECT
    Q_PROPERTY(bool cond READ cond WRITE setCond NOTIFY condChanged)
    Q_PROPERTY(QPoint center READ center WRITE setCenter NOTIFY centerChanged)
    bool m_cond;

    QPoint m_center;

public:
    explicit BallObj(QObject *parent = nullptr);

bool cond() const;

QPoint center() const;

signals:
    void finished();

    void condChanged(bool cond);

    void centerChanged(QPoint center);

public slots:
    void run();
    void setCond(bool cond);
    void setCenter(QPoint center);
};

#endif // BALLOBJ_H
