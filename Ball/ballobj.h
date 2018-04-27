#ifndef BALLOBJ_H
#define BALLOBJ_H

#include <QObject>
#include <QPoint>

class BallObj : public QObject
{
    Q_OBJECT
    Q_PROPERTY(bool cond READ cond WRITE setCond NOTIFY condChanged)
    Q_PROPERTY(QPoint center READ center WRITE setCenter NOTIFY centerChanged)
    Q_PROPERTY(int CenterY READ CenterY WRITE setCenterY NOTIFY CenterYChanged)
    bool m_cond;
    QPoint m_center;
    int m_CenterY;

public:
    explicit BallObj(QObject *parent = nullptr);
    bool cond() const;
    QPoint center() const;
    int CenterY() const;

signals:
    void finished();
    void condChanged(bool cond);
    void centerChanged(QPoint center);
    void CenterYChanged(int CenterY);

public slots:
	void processing();
    void setCond(bool cond);
    void setCenter(QPoint center);
    void setCenterY(int CenterY);
};

#endif // BALLOBJ_H
