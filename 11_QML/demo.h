#ifndef DEMO_H
#define DEMO_H

#include <QObject>

class Demo : public QObject
{
    Q_OBJECT
public:
    explicit Demo(QObject *parent = nullptr);

signals:

public slots:
};

#endif // DEMO_H