#ifndef ACCELERATION_H
#define ACCELERATION_H

#include <QObject>

class Acceleration : public QObject
{
    Q_OBJECT
    Q_PROPERTY(double acceleration
               READ getAcceleration
               NOTIFY changed)
public:
    explicit Acceleration(QObject *parent = nullptr);

    Q_INVOKABLE double getAcceleration() const;
signals:
    void changed(double v);

public slots:
    void onSpeedChanged(double v);

private:
    double currentSpeed = 0;
    double acceleration;
};

#endif // ACCELERATION_H
