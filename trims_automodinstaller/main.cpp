#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include "signalsclass.h"
#include <QCoreApplication>



int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    SignalsClass signalsClass;

    QQmlApplicationEngine engine;
    QObject::connect(
        &engine,
        &QQmlApplicationEngine::objectCreationFailed,
        &app,
        []() { QCoreApplication::exit(-1); },
        Qt::QueuedConnection);
    engine.loadFromModule("trims_automodinstaller", "Main");

    QQmlContext * rootContext = engine.rootContext();
    rootContext->setContextProperty("signals", &signalsClass) ;

    return app.exec();
}
