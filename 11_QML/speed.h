#ifndef SPEED_H
#define SPEED_H

#include <QObject>

class Speed : public QObject
{
    Q_OBJECT

    Q_PROPERTY(double currentDisplacement
               READ getCurrentSpeed
               WRITE onDisplacementChanged
               NOTIFY changed)
public:
    explicit Speed(QObject *parent = nullptr);
    Q_INVOKABLE double getCurrentSpeed() const;

signals:
    void changed(double v);

public slots:
    void onDisplacementChanged(double v);

private:
    double currentDisplacement;
    double speed;

};

#endif // SPEED_H
