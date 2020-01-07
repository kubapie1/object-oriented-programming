#include <QGuiApplication>
#include <QQmlApplicationEngine>

#include "demo.h"
#include "acceleration.h"
#include "displacement.h"
#include "speed.h"

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);

    qmlRegisterType<Demo>("pl.gwizdz", 1, 0, "Demo");
    qmlRegisterType<Acceleration>("pl.kuba", 1, 0, "Acceleration");
    qmlRegisterType<Displacement>("pl.kuba", 1, 0, "Displacement");
    qmlRegisterType<Speed>("pl.kuba", 1, 0, "Speed");

    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    if (engine.rootObjects().isEmpty())
        return -1;

    return app.exec();
}
