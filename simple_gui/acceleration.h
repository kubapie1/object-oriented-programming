#ifndef ACCELERATION_H
#define ACCELERATION_H

#include <QObject>

class Acceleration : public QObject
{
    Q_OBJECT
public:
    explicit Acceleration(QObject *parent = nullptr);

signals:
    void changed(double v);
public slots:
    void onSpeedChanged(double v);

private:
    double currentSpeed = 0;
};

#endif // ACCELERATION_H
