#ifndef CALCULATE_H
#define CALCULATE_H

#include <QObject>
#include <QPoint>

class Calculate : public QObject
{
    Q_OBJECT
    Q_PROPERTY(bool cond READ cond WRITE setcond NOTIFY condChanged)
    Q_PROPERTY(QPoint center READ center WRITE setCenter NOTIFY centerChanged)

    bool m_cond;
    int bounce;
    int rad;
    QPoint m_center;

public:
    explicit Calculate(QObject *parent = nullptr);
    bool cond() const;
    QPoint center() const;
    int getBounce() const;
    int getRad() const;
    bool floor_roof(bool flag);

signals:

    void condChanged(bool cond);
    void finished();
    void sendCoor(int y);
    void centerChanged(QPoint center);
	void bounceChanged(int b);

public slots:
	void processing();
    void setcond(bool cond);
    void setBounce(int b);
    void setCenter(QPoint center);
};

#endif // CALCULATE_H
